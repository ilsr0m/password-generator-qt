#include "widget.h"

void Widget::initSpinBox(QSpinBox *&spinBox, int minimum, int maximum) {
  if (!spinBoxWrapper)
    spinBoxWrapper = new QVBoxLayout;

  spinBox = new QSpinBox(this);

  // set value range of spin box
  spinBox->setMinimum(minimum);
  spinBox->setMaximum(maximum);

  // add spin box into wrapper
  spinBoxWrapper->addWidget(spinBox);
}

void Widget::initSpinLabel(QLabel *&label, QString text) {
  if (!spinBoxWrapper)
    spinBoxWrapper = new QVBoxLayout;

  label = new QLabel(this);
  label->setText(text);

  // add label into wrapper
  spinBoxWrapper->addWidget(label);
}

void Widget::initCheckBox(QCheckBox *&checkBox, QString text) {
  if (!checkBoxWrapper)
    checkBoxWrapper = new QVBoxLayout;

  checkBox = new QCheckBox(this);
  checkBox->setChecked(true); // set check mark
  checkBox->setText(text);

  // checkbox into wrapper
  checkBoxWrapper->addWidget(checkBox);
}

Widget::Widget(QWidget *parent) : QWidget(parent) {
  this->setWindowTitle("Password generator");
  // Inizializing widgets and put them into layouts
  // inizializing labels for spin boxes
  initSpinLabel(labelGenAmount, "Number of passwords:");
  initSpinBox(spinBoxGenerationAmount, 1, 1000);
  initSpinLabel(labelPassLen, "Password length:");
  initSpinBox(spinBoxPasswordLength, 8, 250);
  spinBoxWrapper->setAlignment(Qt::AlignTop);

  // inizializing check boxes
  initCheckBox(checkDigits, "Allow digits");
  initCheckBox(checkLowercaseLetter, "Allow lowercase letters");
  initCheckBox(checkUppercaseLetter, "Allow uppercase letters");
  initCheckBox(checkOtherChars, "Allow other characters");
  initCheckBox(checkAvoidAmbiguous, "Avoid ambiguous characters");
  checkBoxWrapper->setAlignment(Qt::AlignTop);

  // inizializing button
  buttonGenerate = new QPushButton(this);
  buttonGenerate->setText("Generate");
  buttonGenerate->setMinimumHeight(70);

  // inizializing list view
  listViewPasswords = new QListView(this);
  listViewPasswords->setMinimumSize(300, 500);

  model = new DataListModel(this);
  listViewPasswords->setModel(model);

  // set main layout
  this->setLayout(new QHBoxLayout);
  QVBoxLayout *leftLayout = new QVBoxLayout();
  QVBoxLayout *rightLayout = new QVBoxLayout();

  // separate window parts horizontally
  layout()->addItem(leftLayout);
  layout()->addItem(rightLayout);

  // put list view into left layout
  leftLayout->addWidget(listViewPasswords);

  // put others into right layout
  rightLayout->addItem(spinBoxWrapper);
  rightLayout->addItem(checkBoxWrapper);
  rightLayout->addWidget(buttonGenerate);

  connect(buttonGenerate, SIGNAL(clicked()), this,
          SLOT(insertValuesInListView()));
}

Widget::~Widget() {}

void Widget::insertValuesInListView() {

  // put boolean values in bit array to send it to the next slot
  QBitArray bools(5); // true/false
  bools[0] = checkDigits->isChecked();
  bools[1] = checkLowercaseLetter->isChecked();
  bools[2] = checkUppercaseLetter->isChecked();
  bools[3] = checkOtherChars->isChecked();
  bools[4] = checkAvoidAmbiguous->isChecked();

  // fill list view with generated passwords
  model->fillData(bools, spinBoxPasswordLength->value(),
                  spinBoxGenerationAmount->value());
}
