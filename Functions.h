#pragma once
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;

string lowerCase(string);						// Tüm karakterleri küçük harflere çevirir.

string readText();								// Metni dosyadan okur.

void readQuestion();							// Soruları dosyadan okur.

string excludeStopWords(string);				// Stop Word'leri cümleden çıkartır.

string eliminateWords(string, string);			// Soru ile cevap cümlesinde aynı olan kelimeleri çıkartır.

string sentenceFinder(string,string);			// Sorunun son kelimesine bağlı olarak cevap cümlesini bulur.

bool matchSentence(string,string);				// Soru ile cevap cümlesindeki tüm kelimeler uyuşuyor mu diye bakar.

string clearSentence(string);					// Cümlenin başındaki ve sonundaki boşluk, nokta, soru işareti vb. siler.
