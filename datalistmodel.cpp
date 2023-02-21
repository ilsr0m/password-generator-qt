#include "datalistmodel.h"
#include "charactersetbuilder.h"
#include "passwordgenerator.h"
#include <QMessageBox>

DataListModel::DataListModel(QObject *parent) : QAbstractItemModel(parent) {
  m_data = QList<QString>();
}

int DataListModel::columnCount(const QModelIndex &parent) const { return 1; }

int DataListModel::rowCount(const QModelIndex &parent) const {
  return m_data.size();
}

QVariant DataListModel::data(const QModelIndex &index, int role) const {
  if (role == Qt::DisplayRole) {
    return m_data.at(index.row());
  }
  return QVariant();
}

QModelIndex DataListModel::index(int row, int column,
                                 const QModelIndex &parent) const {
  return createIndex(row, column, (void *)&m_data[row]);
}

QModelIndex DataListModel::parent(const QModelIndex &index) const {
  return QModelIndex();
}

void DataListModel::fillData(QBitArray bools, int length, int loops) {
  // initialize char set, building its settings
  CharacterSet chars = CharacterSetBuilder()
                           .setDigits(bools[0])
                           .setLowercase(bools[1])
                           .setUppercase(bools[2])
                           .setOthers(bools[3])
                           .avoidAmbiguous(bools[4]);

  // warning message box appears in case chars are empty
  if (chars.getCharacters().isEmpty()) {
    QMessageBox::warning(NULL, "Not enough password settings",
                         "Please, choose at least one of these settings:"
                         "\n1. Allow digits"
                         "\n2. Allow lowercase letters"
                         "\n3. Allow uppercase letters"
                         "\n4. Allow other characters\n");
    return;
  }

  // clear in case it is not empty
  if (!m_data.empty())
    m_data.clear();

  // generate
  m_data = passgen::generate(chars, length, loops);
  // notify list view about data changing
  emit layoutChanged();
}
