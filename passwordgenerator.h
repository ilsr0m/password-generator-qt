#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include "characterset.h"
#include <QList>
#include <QString>

class PasswordGenerator {
public:
  PasswordGenerator();
  static QList<QString> generate(CharacterSet permissibleCharacters,
                                 int passwordlLength, int loops = 1);
};
typedef PasswordGenerator passgen;

#endif // PASSWORDGENERATOR_H
