#ifndef CHARACTERSET_H
#define CHARACTERSET_H

#include <QString>

class CharacterSet {
  QString characters;
  int length;

public:
  CharacterSet();
  QString getCharacters() const;
  void setCharacters(const QString &newCharacters);
  int getLength() const;
  operator QString &&();
};

#endif // CHARACTERSET_H
