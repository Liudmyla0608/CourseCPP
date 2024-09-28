    
//Чи є в тексті слова, що починаються та закінчуються однією і тією ж літерою?

#include <iostream>
#include <string>
using namespace std;
int main()
{


    string text;
    int n = 1;
    int k = 0;
    string reversed;
    

    
    cout << "enter text" << endl;
    getline(cin, text);
    
    string::size_type e;
    string::size_type middle = 0;
    string::size_type i = 0;
    string::size_type pos = text.find(' ', i);
      if(text[i] == text[pos-1]){ //check first word
        k++;
    }
    
    while(pos != string::npos)
    {
        n++;
        pos += 1; // the firs letter next word
        middle = pos;
        pos = text.find(' ', pos);
        if(text[middle] == text[pos-1]) //check middle words
        {
        k++;
        }
        
    }
    
    //check the last word
    for(int i = text.length() - 1;i>= 0; --i)
    reversed += text[i];
    
    string::size_type posE = reversed.find(' ', i);
    if(reversed[i] == reversed[posE - 1])
    k++;
    
    
  
   
    if (k >= 1){
        cout << "text has words that starts and ends the same letter" << endl;
    }else{
        cout << "text has no words that starts and ends the same letter" << endl;
    }
    
    
    
    cout << "number of words = "<< n << endl;
    cout << "number of words that starts and ends the same letter : "<< k << endl;
    
 
    
    return 0;
}
