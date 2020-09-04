#include "Functions.h"

string stopList[174] = { "a","about","above","after","again","against","all","am","an","and","any","are","aren't","as","at",
"be","because","been","before","being","below","between","both","but","by","can't","cannot","could","couldn't",
"did","didn't","do","does","doesn't","doing","don't","down","during","each","few","for","from","further","had",
"hadn't","has","hasn't","have","haven't","having","he","he'd","he'll","he's","her","here","here's","hers","herself",
"him","himself","his","how","how's","i","i'd","i'll","i'm","i've","if","in","into","is","isn't","it","it's","its","itself",
"let's","me","more","most","mustn't","my","myself","no","nor","not","of","off","on","once","only","or","other","ought","our","ours",
"ourselves","out","over","own","same","shan't","she","she'd","she'll","she's","should","shouldn't","so","some","such","than","that","that's",
"the","their","theirs","them","themselves","then","there","there's","these","they","they'd","they'll","they're","they've","this","those","through",
"to","too","under","until","up","very","was","wasn't","we","we'd","we'll","we're","we've","were","weren't","what","what's","when","when's","where",
"where's","which","while","who","who's","whom","why","why's","with","won't","would","wouldn't","you","you'd","you'll","you're","you've","your","yours",
"yourself","yourselves" };

string lowerCase(string s) 
{
	
	for (int a = 0; a < s.length(); a++) 
	{
		if (int(s[a] >= 65) && int(s[a] <= 90))
			{
				s[a] = char(int(s[a]) + 32);
			}
	}
	return s;
}

string readText() 
{
	int fnd;
	string line, tempT;
	fstream file;
	file.open("the_truman_show_script.txt");
	while (!file.eof()) 
	{
		getline(file, line);
		tempT = line;
		tempT = lowerCase(tempT);
	}
	file.close();
	return tempT;
}

void readQuestion()
{
	string line, tempQ, text;
	fstream file;
	int i = 1;
	file.open("questions.txt");
	text = readText();
	while (!file.eof())
	{
		getline(file, line);
		tempQ = line;
		tempQ = lowerCase(tempQ);
		tempQ = clearSentence(tempQ);
		cout << i << ")" << line << endl; i++;
		cout << "->" << clearSentence(eliminateWords(sentenceFinder(text, tempQ), tempQ)) << endl << endl;
	}
	file.close();
}

string excludeStopWords(string s) 
{
	int space1=0, space1_f=0, space2=s.find(" "), space2_f= 1;
	string temp;
	bool first = 0;
	while (true) {
		temp = s.substr(space1, (space2-space1));
		for (int n = 0; n < 174; n++)
		{
			if (temp == stopList[n]) 
			{ 
				if (space1 == 0) 
				{
					s.erase(s.find(temp), temp.length() + 1); space1 = 0; space2 = s.find(" "); first = 1; break;
				}
				else 
				{
					s.erase(space1 - 1, temp.length() + 1); space1 = space1_f; space2 = space2_f; break;
				}
				
			}
		}
		if (first == 1) { first = 0; continue; }
		space1_f = space1; space2_f = space2;
		space1++, space2++;
		space1 = s.find(" ", space1) + 1;
		space2 = s.find(" ", space2);
		if (space1 == 0) { break; }
		if (space2 == -1) { space2 = s.length(); }	
	}
	return s;
}

string eliminateWords(string sntc, string qst)
{
	int space1 = 0, space1_f = 0, space2 = qst.find(" "), space2_f = 1;
	string temp;
	bool first = 0;
	if (sntc == "-1") { return "-1"; }
	while (true)
	{
		temp = qst.substr(space1, (space2 - space1));
		if (sntc.find(temp) != -1)
		{
			if (sntc.find(temp)==0)
			{
				sntc.erase(sntc.find(temp), temp.length() + 1);
			}
			else
			{
				sntc.erase(sntc.find(temp)-1, temp.length() + 1);
			}
		}		
		if (first == 1) { first = 0; continue; }
		space1_f = space1; space2_f = space2;
		space1++, space2++;
		space1 = qst.find(" ", space1) + 1;
		space2 = qst.find(" ", space2);
		if (space1 == 0) { break; }
		if (space2 == -1) { space2 = sntc.length(); }
	}
	return sntc;
}

string sentenceFinder(string txt, string qst) 
{
	int firstDot, lastDot, lwPlace=0;
	string lastWord = qst, sentence, text = txt;
	lastWord = lastWord.erase(0, lastWord.find_last_of(' ') + 1); lastWord = lastWord.substr(0, lastWord.length());
	while (true)
	{
		lwPlace = txt.find(lastWord,lwPlace);
		if (lwPlace == -1) { return "-1"; }
		firstDot = lwPlace;
		while ( txt[firstDot] != '.')
		{
			firstDot--;
			if (firstDot <= 0) 
			{ 
				firstDot = 0; 
				break; 
			} 
		}
		lastDot = lwPlace;
		while ( txt[lastDot] != '.')
		{ 
			lastDot++;
		}	
		sentence = txt.substr(firstDot , lastDot - firstDot );
		sentence = clearSentence(sentence);
		if (matchSentence(sentence,qst)) 
		{
			return sentence;
		}
		else 
		{
			lwPlace++;
		}
	}
}

string clearSentence(string sntc)
{
	int a;
	string temp = sntc;
	if (sntc == "-1") { return "No answer found."; }
	while (!(int(temp[0]) >= 97 && int(temp[0]) <= 122) && !(int(temp[0]) >= 48 && int(temp[0]) <= 57))
	{
		temp = temp.substr(1,temp.length()-1);
	}
	a = temp.length();
	while (!(int(temp[a-1]) >= 97 && int(temp[a-1]) <= 122) && !(int(temp[a - 1]) >= 48 && int(temp[a - 1]) <= 57))
	{
		temp = temp.substr(0, temp.length() - 1);
		a = temp.length();
	}
	for (int i = 0; i < sntc.length(); i++) { if (sntc[i] == ',') { sntc.erase(i, 1); } }
	temp = excludeStopWords(temp);
	return temp;
}

bool matchSentence(string sntc, string qst)
{
	int space1 = 0, space2 = qst.find(" "), matchCount = 0, sentenceSpaceCount = 0, spacePoint = 0;
	string temp;
	bool first = 0;
	while (true) 
	{ 
		spacePoint = sntc.find(" ", spacePoint); 
		if (spacePoint == -1) { break; }
		spacePoint++;
		sentenceSpaceCount++; 
	}
	while (true)
	{
		temp = qst.substr(space1, (space2 - space1));
		if (sntc.find(temp) != -1)
		{
			matchCount++;
		}
		space1++, space2++;
		space1 = qst.find(" ", space1) + 1;
		space2 = qst.find(" ", space2);
		if (space1 == 0) { break; }
		if (space2 == -1) { space2 = qst.length() - 1; }

	}
	if (matchCount == sentenceSpaceCount) { return true; }
	else { return false; }
}
