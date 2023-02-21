#ifndef DATALISTMODEL_H
#define DATALISTMODEL_H
#include "characterset.h"
#include <QAbstractItemModel>
#include <QBitArray>
#include <QList>
#include <QString>

class DataListModel : public QAbstractItemModel {
  Q_OBJECT
  QList<QString> m_data;

public:
  DataListModel(QObject *);
  virtual int columnCount(const QModelIndex &parent) const;
  virtual int rowCount(const QModelIndex &parent) const;
  virtual QVariant data(const QModelIndex &index, int role) const;
  virtual QModelIndex index(int row, int column,
                            const QModelIndex &parent) const;

  virtual QModelIndex parent(const QModelIndex &index) const;

  // public slots:
  void fillData(QBitArray, int, int);
};

#endif // DATALISTMODEL_H
