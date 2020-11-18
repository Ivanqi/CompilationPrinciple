#include "CharSet.h"

vector<char> CharSet::ascii = CharSet::asciiDeclare();

vector<char> CharSet::letterAndDigits = CharSet::letterAndDigitsDeclare();

vector<char> CharSet::Alphabet = CharSet::ascii;

CharSet* CharSet::digit = new CharSet('0', '9');                // 数字
CharSet* CharSet::smallLetter = new CharSet('a', 'z');          // 小写字母
CharSet* CharSet::capitalLeter = new CharSet('A', 'Z');         // 大写字母
CharSet* CharSet::letter = CharSet::initLetterDeclare();               // 字母，包括大写和小写
CharSet* CharSet::letterOrDigit = CharSet::initLetterOrDigitDeclare(); // 字母和数字
CharSet* CharSet::whiteSpace = CharSet::initWhiteSpaceDeclare();       // 空白字符

void CharSet::addSubSet(CharSet *charSet)
{
    subSets.push_back(charSet);
}

 /**
 * 某个字符是否属于本集合
 */
bool CharSet::match(char ch)
{
    bool rtn = false;
    if (subSets.size() > 0) {
        for (CharSet *subSet: subSets) {
            rtn = subSet->match(ch);
            if (rtn){
                break;
            }
        }
    } else {
        rtn = (fromChar <= ch && ch <= toChar);
    }

    if (exclude) {
        rtn = !rtn;
    }

    return rtn;
}

string CharSet::toString()
{
    if (subSets.size() > 0) {
        string sb;
        if (exclude) {
            sb.append("^");
            if (subSets.size() > 1) {
                sb.append("(");
            }
        }

        for (int i = 0; i < subSets.size(); i++) {
            if (i > 0) {
                sb.append("|");
            }
            sb.append(subSets[i]->toString());
        }

        if (exclude && subSets.size() > 1) {
            sb.append(")");
        }

        return sb;
    } else if (fromChar == toChar) {
        string sb;
        sb.push_back(fromChar);
        return sb;
    } else {
        string fromCharS;
        string toCharS;
        fromCharS.push_back(fromChar);
        toCharS.push_back(toChar);
        if (exclude) {
            return "[^" + fromCharS + " - " + fromCharS + "]";
        } else {
            return "[" + fromCharS + " - " + fromCharS + "]";
        }
    }
}

/**
 * 返回一个等价的集合，但是显示的时候更简短
 * 比如, a|b|....z就显示成[a - z]就行了
 */
CharSet* CharSet::getShorterForm()
{
    if (equals(digit)) {
        return digit;
    } else if (equals(smallLetter)) {
        return smallLetter;
    } else if (equals(capitalLeter)) {
        return capitalLeter;
    } else if (equals(letter)) {
        return letter;
    } else if (equals(letterOrDigit)) {
        return letterOrDigit;
    } else {
        CharSet *charSet = getSupplementarySet();
        charSet->exclude = true;
        return charSet;
    }
}


// 计算补集
CharSet* CharSet::getSupplementarySet()
{
    CharSet *charSet = new CharSet();

    for (char ch: letterAndDigits) {    // TODO 需要直到该词法更准确的字符集
        if (!match(ch)) {
            charSet->addSubSet(new CharSet(ch));
        }
    }

    if (charSet->subSets.size() == 0) {
        charSet == letterOrDigit;
    }

    return charSet;
}

/**
 * 初始化字母表。目前支持整个ASCII表，128个值
 */
vector<char> CharSet::asciiDeclare()
{
    vector<char> Alphabet;

    for (int i = 0; i < 128; i++) {
        Alphabet.push_back((char)i);
    }

    return Alphabet;
}

/**
 * 包含字母和数字的字母表
 */
vector<char> CharSet::letterAndDigitsDeclare()
{
    vector<char> Alphabet;

    for (char i = '0'; i <= '9'; i++) {
        Alphabet.push_back((char)i);
    }

    for (char i = 'A'; i <= 'Z'; i++) {
        Alphabet.push_back((char)i);
    }

    for (char i = 'a'; i <= 'z'; i++) {
        Alphabet.push_back((char)i);
    }

    return Alphabet;
}

CharSet* CharSet::initLetterOrDigitDeclare()
{
    CharSet *charSet = new CharSet();
    charSet->addSubSet(digit);
    charSet->addSubSet(smallLetter);
    charSet->addSubSet(capitalLeter);
    return charSet;
}

CharSet* CharSet::initLetterDeclare()
{
    CharSet *charSet = new CharSet();
    charSet->addSubSet(smallLetter);
    charSet->addSubSet(capitalLeter);
    return charSet;
}


CharSet* CharSet::initWhiteSpaceDeclare()
{
    CharSet *charSet = new CharSet();
    charSet->addSubSet(new CharSet(' '));
    charSet->addSubSet(new CharSet('\t'));
    charSet->addSubSet(new CharSet('\n'));
    return charSet;
}

bool CharSet::equals(Any obj)
{
    CharSet *charSet = obj.as<CharSet*>();
    for (char ch: Alphabet) {
        if (charSet->match(ch)) {
            if (!match(ch)) {
                return false;
            }
        } else {
            if (match(ch)) {
                return false;
            }
        }
    }
}

// 是不是空集
bool CharSet::isEmpty()
{
    if (subSets.size() > 0) {
        bool empty = true;
        for (CharSet *charSet: subSets) {
            if (!charSet->isEmpty()) {
                empty = false;
                break;
            }
        }
        return empty;
    } else {
        return fromChar == '\0';
    }
}