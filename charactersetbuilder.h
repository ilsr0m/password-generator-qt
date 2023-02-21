#ifndef CHARACTERSETBUILDER_H
#define CHARACTERSETBUILDER_H
#include "characterset.h"
#include <QSet>

class CharacterSetBuilder {
  CharacterSet charSet;

public:
  CharacterSetBuilder();
  CharacterSetBuilder &setDigits(bool include);
  CharacterSetBuilder &setLowercase(bool include);
  CharacterSetBuilder &setUppercase(bool include);
  CharacterSetBuilder &setOthers(bool include);
  CharacterSetBuilder &avoidAmbiguous(bool include);
  operator CharacterSet &&();
};

#endif // CHARACTERSETBUILDER_H
