#include "passwordgenerator.h"
#include <QRandomGenerator>

PasswordGenerator::PasswordGenerator() {}

// generation password function
QList<QString> PasswordGenerator::generate(CharacterSet permissibleSet,
                                           int passwordlLength, int loops) {
  if (loops > 0 && !permissibleSet.getCharacters().isEmpty()) {

    QRandomGenerator *ranGen = QRandomGenerator::global();

    // set length of permissible symbols and permissible chars
    int charLength = permissibleSet.getLength();
    QString chars = permissibleSet.getCharacters();

    QList<QString> passwordList;

    // generation of each password
    while (loops != 0) {
      QString password;
      for (int i = 0; i < passwordlLength; ++i)
        password += chars[ranGen->bounded(0, charLength)];
      // add generated password to list
      passwordList.append(password);
      --loops;
    }
    return passwordList;
  }

  return QList<QString>();
}
