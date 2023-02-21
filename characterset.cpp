#include "characterset.h"

QString CharacterSet::getCharacters() const { return characters; }

void CharacterSet::setCharacters(const QString &newCharacters) {
  length = newCharacters.length();
  characters = newCharacters;
}

int CharacterSet::getLength() const { return length; }

CharacterSet::operator QString &&() { return std::move(characters); }

CharacterSet::CharacterSet() {
  characters = QString();
  length = 0;
}
