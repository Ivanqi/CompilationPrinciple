#include "CharSet.h"
#include <string.h>

vector<char> CharSet::ascii = CharSet::asciiDeclare();

vector<char> CharSet::letterAndDigits = CharSet::letterAndDigitsDeclare();

vector<char> CharSet::Alphabet = CharSet::ascii;

shared_ptr<CharSet> CharSet::digit = shared_ptr<CharSet>(new CharSet('0', '9'));                        // 数字
shared_ptr<CharSet> CharSet::smallLetter = shared_ptr<CharSet>(new CharSet('a', 'z'));                  // 小写字母
shared_ptr<CharSet> CharSet::capitalLeter = shared_ptr<CharSet>(new CharSet('A', 'Z'));                 // 大写字母
shared_ptr<CharSet> CharSet::letter = shared_ptr<CharSet>(CharSet::initLetterDeclare());                // 字母，包括大写和小写
shared_ptr<CharSet> CharSet::letterOrDigit = shared_ptr<CharSet>(CharSet::initLetterOrDigitDeclare());  // 字母和数字
shared_ptr<CharSet> CharSet::whiteSpace = shared_ptr<CharSet>(CharSet::initWhiteSpaceDeclare());        // 空白字符

void CharSet::addSubSet(shared_ptr<CharSet>& charSet)
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
        for (size_t i = 0; i < subSets.size(); i++) {
            rtn = subSets[i]->match(ch);
            if (rtn){
                break;
            }
        }
    } else {
        if (fromChar_ != ' ' && toChar_ != ' ') {
            rtn = (fromChar_ <= ch && ch <= toChar_);
        }
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
    } else if (fromChar_ == toChar_) {
        string sb;
        sb.push_back(fromChar_);
        return sb;
    } else {
        string fromCharS;
        string toCharS;
        fromCharS.push_back(fromChar_);
        toCharS.push_back(toChar_);
        string sb;
        if (exclude) {
            sb.append("[^").append(fromCharS).append(" - ").append(toCharS).append("]");
        } else {
            sb.append("[").append(fromCharS).append(" - ").append(toCharS).append("]");
        }
        return sb;
    }
}

/**
 * 返回一个等价的集合，但是显示的时候更简短
 * 比如, a|b|....z就显示成[a - z]就行了
 */
CharSet* CharSet::getShorterForm()
{
    if (equals(digit)) {
        return digit.get();
    } else if (equals(smallLetter)) {
        return smallLetter.get();
    } else if (equals(capitalLeter)) {
        return capitalLeter.get();
    } else if (equals(letter)) {
        return letter.get();
    } else if (equals(letterOrDigit)) {
        return letterOrDigit.get();
    } else {
        shared_ptr<CharSet> charSetPtr = getSupplementarySet();
        charSetPtr->exclude = true;
        return charSetPtr.get();
    }
}

shared_ptr<CharSet> CharSet::getShorterFormx() {
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
        shared_ptr<CharSet> charSetPtr = getSupplementarySet();
        charSetPtr->exclude = true;
        return charSetPtr;
    }
}

/**
 * @brief 计算补集
 *   1. 当你的chlist = [1-9], 不符合 digit集合的[0-9]，所以通过计算补集，补上一个0
 *   2. 当的你的chlist = [1-9|a-d], 不符合digit集合的[0-9]和smallLetter的[a-z]，所以要补0和[c-z]
 * 
 * @return     shared_ptr<CharSet> 
 */
shared_ptr<CharSet> CharSet::getSupplementarySet()
{
    shared_ptr<CharSet> charSetPtr = shared_ptr<CharSet>(new CharSet());
    
    for (char ch: letterAndDigits) {    // TODO 需要直到该词法更准确的字符集
        if (!match(ch)) {
            shared_ptr<CharSet> matchVal = shared_ptr<CharSet>(new CharSet(ch));
            charSetPtr->addSubSet(matchVal);
        }
    }

    if (charSetPtr->subSets.size() == 0) {
        charSetPtr.swap(letterOrDigit);
    }
    return charSetPtr;
}

/**
 * 初始化字母表。目前支持整个ASCII表，128个值
 */
vector<char> CharSet::asciiDeclare()
{
    vector<char> alphabet;

    for (int i = 0; i < 128; i++) {
        alphabet.emplace_back((char)i);
    }

    return alphabet;
}

/**
 * 包含字母和数字的字母表(总数)
 */
vector<char> CharSet::letterAndDigitsDeclare()
{
    vector<char> Alphabet;

    for (char i = '0'; i <= '9'; i++) {
        Alphabet.emplace_back((char)i);
    }

    for (char i = 'A'; i <= 'Z'; i++) {
        Alphabet.emplace_back((char)i);
    }

    for (char i = 'a'; i <= 'z'; i++) {
        Alphabet.emplace_back((char)i);
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
    auto space = shared_ptr<CharSet>(new CharSet(' '));
    auto interval = shared_ptr<CharSet>(new CharSet('\t'));
    auto linbreak = shared_ptr<CharSet>(new CharSet('\n'));

    charSet->addSubSet(space);
    charSet->addSubSet(interval);
    charSet->addSubSet(linbreak);
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
    return true;
}

/**
 * @brief charset 比较
 *  1. 规定了值的范畴，即ascii的范围
 *  2. 在ascii的范围内，判断obj是否这个范围，在判断this的范围是否符合ascii和obj的范围
 * 
 * @param obj 
 * @return true 
 * @return false 
 */
bool CharSet::equals(shared_ptr<CharSet> obj) {
    for (char ch: Alphabet) {
        if (obj->match(ch)) {
            if (!match(ch)) {
                return false;
            }
        } else {
            if (match(ch)) {
                return false;
            }
        }
    }
    return true;
}

// 是不是空集
bool CharSet::isEmpty()
{
    if (subSets.size() > 0) {
        bool empty = true;
        for (size_t i = 0; i < subSets.size(); i++) {
            CharSet *charSet = subSets[i].get();
            if (!charSet->isEmpty()) {
                empty = false;
                break;
            }
        }
        return empty;
    } else {
        return fromChar_ == ' ';
    }
}