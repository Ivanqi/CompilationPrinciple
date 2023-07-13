#include <iostream>
#include <string>
#include <CharSet.h>

using namespace std;

void test_case_1() {

    string digit = CharSet::digit->toString();
    cout << "digit: " << digit << endl;

    string smallLetter = CharSet::smallLetter->toString();
    cout << "smallLetter: " << smallLetter << endl;

    string capitalLeter = CharSet::capitalLeter->toString();
    cout << "capitalLeter: " << capitalLeter << endl;

    string letter = CharSet::letter->toString();
    cout << "letter: " << letter << endl;

    string letterOrDigit = CharSet::letterOrDigit->toString();
    cout << "letterOrDigit: " << letterOrDigit << endl;

    string whiteSpace = CharSet::whiteSpace->toString();
    cout << "whiteSpace: " << whiteSpace << endl;

    cout << "ascii: ";
    for (char ch: CharSet::ascii) {
        cout << "\t" << (int)ch << "\t";
    }
    cout  << endl;

    cout << "\n Alphabet: ";
    for (char ch: CharSet::Alphabet) {
        cout << "\t" << (int)ch << "\t";
    }
    cout  << endl;

}

void test_case_2() {
    cout << "\n数字" << endl;
    cout << (CharSet::digit->match('1') ? "true" : "fail") << endl;
    cout << (CharSet::digit->match('a') ? "true" : "fail") << endl;

    cout << "\n小写字母" << endl;
    cout << (CharSet::smallLetter->match('1') ? "true" : "fail") << endl;
    cout << (CharSet::smallLetter->match('a') ? "true" : "fail") << endl;
    cout << (CharSet::smallLetter->match('A') ? "true" : "fail") << endl;

    cout << "\n大写字母" << endl;
    cout << (CharSet::capitalLeter->match('1') ? "true" : "fail") << endl;
    cout << (CharSet::capitalLeter->match('a') ? "true" : "fail") << endl;
    cout << (CharSet::capitalLeter->match('A') ? "true" : "fail") << endl;

    cout << "\n字母，包括大写和小写" << endl;
    cout << (CharSet::letter->match('1') ? "true" : "fail") << endl;
    cout << (CharSet::letter->match('a') ? "true" : "fail") << endl;
    cout << (CharSet::letter->match('A') ? "true" : "fail") << endl;

    cout << "\n字母和数字" << endl;
    cout << (CharSet::letterOrDigit->match('1') ? "true" : "fail") << endl;
    cout << (CharSet::letterOrDigit->match('a') ? "true" : "fail") << endl;
    cout << (CharSet::letterOrDigit->match('A') ? "true" : "fail") << endl;
}

void test_case_3() {
    CharSet* letterOrDigit = CharSet::letterOrDigit->getShorterForm();
    cout << "\n" << letterOrDigit->toString() << endl;

    shared_ptr<CharSet> cod = shared_ptr<CharSet>(new CharSet());
    shared_ptr<CharSet> a1 = shared_ptr<CharSet>(new CharSet('1'));
    shared_ptr<CharSet> a2 = shared_ptr<CharSet>(new CharSet('2'));
    shared_ptr<CharSet> a3 = shared_ptr<CharSet>(new CharSet('3'));
    shared_ptr<CharSet> a4 = shared_ptr<CharSet>(new CharSet('4'));
    shared_ptr<CharSet> a5 = shared_ptr<CharSet>(new CharSet('5'));
    shared_ptr<CharSet> a6 = shared_ptr<CharSet>(new CharSet('6'));
    shared_ptr<CharSet> a7 = shared_ptr<CharSet>(new CharSet('7'));
    shared_ptr<CharSet> a8 = shared_ptr<CharSet>(new CharSet('8'));
    shared_ptr<CharSet> a9 = shared_ptr<CharSet>(new CharSet('9'));
    shared_ptr<CharSet> a10 = shared_ptr<CharSet>(new CharSet('a'));
    shared_ptr<CharSet> a11 = shared_ptr<CharSet>(new CharSet('b'));
    shared_ptr<CharSet> a12 = shared_ptr<CharSet>(new CharSet('c'));
    shared_ptr<CharSet> a13 = shared_ptr<CharSet>(new CharSet('d'));

    cod->addSubSet(a1);
    cod->addSubSet(a2);
    cod->addSubSet(a3);
    cod->addSubSet(a4);
    cod->addSubSet(a5);
    cod->addSubSet(a6);
    cod->addSubSet(a7);
    cod->addSubSet(a8);
    cod->addSubSet(a9);
    cod->addSubSet(a10);
    cod->addSubSet(a11);
    cod->addSubSet(a12);
    cod->addSubSet(a13);

    shared_ptr<CharSet> codStr = cod->getShorterFormx();

    cout << codStr.get()->toString() << endl;
}

int main() {

    test_case_3();
    return 0;
}