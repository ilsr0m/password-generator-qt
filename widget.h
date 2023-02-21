#ifndef WIDGET_H
#define WIDGET_H

#include "datalistmodel.h"
#include <QBitArray>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

// Navigation menu class for the program

class Widget : public QWidget {
  Q_OBJECT
  // |---------------- WIDGET OBJECTS ----------------|
  // Spin box allows user set amount of generated passwords
  QSpinBox *spinBoxGenerationAmount;
  QLabel *labelGenAmount;

  // Spin box allows user set password length
  QSpinBox *spinBoxPasswordLength;
  QLabel *labelPassLen;

  // 4 Check boxes for choosing settings of password style
  QCheckBox *checkDigits;          // if password has digits
  QCheckBox *checkLowercaseLetter; // if password has lowercase letters
  QCheckBox *checkUppercaseLetter; // if password has uppercase letters
  QCheckBox *checkOtherChars;      // if password has other characters
  QCheckBox *checkAvoidAmbiguous;  // in case ambiguous letter must be avoided

  // list view of generated passwords
  QListView *listViewPasswords;

  // push button activating password generation process
  QPushButton *buttonGenerate;

  // wrappers based on layouts
  QVBoxLayout *spinBoxWrapper = NULL;
  QVBoxLayout *checkBoxWrapper = NULL;

  // model object for list view
  DataListModel *model;
  // |---------------- INIT FUNCTIONS ----------------|

  void initSpinBox(QSpinBox *&, int, int);
  void initSpinLabel(QLabel *&, QString);
  void initCheckBox(QCheckBox *&, QString);

public:
  Widget(QWidget *parent = nullptr);

  ~Widget();

public slots:
  void insertValuesInListView();
};
#endif // WIDGET_H
