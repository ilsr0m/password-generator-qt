#include "charactersetbuilder.h"

CharacterSetBuilder::CharacterSetBuilder() { charSet = CharacterSet(); }

CharacterSetBuilder &CharacterSetBuilder::setDigits(bool include = true) {
  if (include)
    charSet.setCharacters(charSet.getCharacters() + "0123456789");
  return *this;
}

CharacterSetBuilder &CharacterSetBuilder::setLowercase(bool include = true) {
  if (include)
    charSet.setCharacters(charSet.getCharacters() +
                          "abcdefghijklmnopqrstuvwxyz");
  return *this;
}

CharacterSetBuilder &CharacterSetBuilder::setUppercase(bool include = true) {
  if (include)
    charSet.setCharacters(charSet.getCharacters() +
                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  return *this;
}

CharacterSetBuilder &CharacterSetBuilder::setOthers(bool include = true) {
  if (include)
    charSet.setCharacters(charSet.getCharacters() +
                          "=+*-\\^/|<>_()[]{}#$@%&?!");
  return *this;
}

CharacterSetBuilder &CharacterSetBuilder::avoidAmbiguous(bool include = true) {
  if ((include) && (charSet.getLength() != 0)) {

    // convert charSet to QSet
    QString chars = charSet;
    QSet<QChar> charsSet(chars.begin(), chars.end());

    // declare ambiguous character set
    QSet<QChar> ambiguousSet = {'0', '1', 'i', 'I', 'l', 'L', 'o', 'O'};
    // substract charsSet
    charsSet -= ambiguousSet;
    // convert final set to new string
    QString newChars;
    foreach (auto ch, charsSet) { newChars += ch; }

    charSet.setCharacters(newChars);
  }
  return *this;
}

CharacterSetBuilder::operator CharacterSet &&() { return std::move(charSet); }
