#include "datalistmodel.h"
#include "passwordgenerator.h"
#include <QAbstractListModel>
#include <QMessageBox>

DataListModel::DataListModel(QObject *parent) : QAbstractItemModel(parent) {
  m_parent = qobject_cast<QWidget *>(parent);
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

void DataListModel::fillModel(CharacterSet permissibleCharacters, int length,
                              int loops) {
  // generate
  m_data = passgen::generate(permissibleCharacters, length, loops);
  // notify list view about data changing
  emit layoutChanged();
}
