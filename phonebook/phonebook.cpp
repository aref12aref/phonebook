#include <iostream>
#include <fstream>
using namespace std;

typedef struct node{
    string name;
    string number;
    struct node* next;
}node;

int add(int help);
int search(int help);

node *pb[26];
ofstream name_data , num_data , test;
ifstream name_data2 , num_data2 , test2;

int main(){
    //get option from user
    int option;
    cout << "welcome to phonebook!\nadd a number->1 search a number->2 ?" << endl;
    cin >> option;
    if(option == 1){
        int help = 1;
        add(help);
        if(help == 1){
            cout << "sorry, please try again later." << endl;
        }
        else if(help == 0){
            cout << "thanks for using our phonebook! see you later." << endl;
        }
    }
    else if(option == 2){
        int help = 1;
        search(help);
        if(help == 1){
            cout << "sorry, please add the name and number to phonebook later." << endl;
        }
        else if(help == 0){
            cout << "thanks for using our phonebook! see you later." << endl;
        }
    }
    else{
        cout << "value error!" << endl;
        return 1;
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------------------

int add(int help){
    //pointring all nodes to NULL
    for(int i = 0 ; i < 26 ; i++){
        pb[i] = NULL;
    }
    
    //get the numbers test from pb test
    int t;
    test2.open("data/pb test.txt", ios::in);
    test2 >> t;
    test2.close();

    //get the name and know in any index must put, get the number
    string name_get, num_get, pname, pnumber;
    int FLtest, FL = -1;
    cout << "name (first letter must be capital!): "; cin >> pname;
    while(FL = -1){
        switch(pname[0]){
            case 'A' : FL = 0; break;
            case 'B' : FL = 1; break;
            case 'C' : FL = 2; break;
            case 'D' : FL = 3; break;
            case 'E' : FL = 4; break;
            case 'F' : FL = 5; break;
            case 'G' : FL = 6; break;
            case 'H' : FL = 7; break;
            case 'I' : FL = 8; break;
            case 'J' : FL = 9; break;
            case 'K' : FL = 10; break;
            case 'L' : FL = 11; break;
            case 'M' : FL = 12; break;
            case 'N' : FL = 13; break;
            case 'O' : FL = 14; break;
            case 'P' : FL = 15; break;
            case 'Q' : FL = 16; break;
            case 'R' : FL = 17; break;
            case 'S' : FL = 18; break;
            case 'T' : FL = 19; break;
            case 'U' : FL = 20; break;
            case 'V' : FL = 21; break;
            case 'W' : FL = 22; break;
            case 'X' : FL = 23; break;
            case 'Y' : FL = 24; break;
            case 'Z' : FL = 25; break;
            default : FL = -1; cout << "value error!" << endl; cout << "name (first letter must be capital!): "; cin >> pname;
        }
    }
    cout << "number: "; cin >> pnumber;

    //make new node and pointer it to the new name and number
    node *n = new(node);
    if(n == NULL){
        cout << "RAM error!" << endl;
        return help;
    }
    n->name = pname;
    n->number = pnumber;
    n->next = NULL;

    //get names from names file and numbers from numbers file, put them into the array
    name_data2.open("data/names.txt", ios::in);
    num_data2.open("data/numbers.txt", ios::in);
    if(name_data2.is_open() && num_data2.is_open()){
        int i = 0;
        while(!name_data2.eof() && !num_data2.eof() && i < t){
            name_data2 >> name_get;
            num_data2 >> num_get;
            i++;
            node *nd = new(node);
            if(nd == NULL){
                cout << "RAM error!" << endl;
                for(int d = 0 ; d < 26 ; d++){
                    while(pb[d] != NULL){
                        node *tmp = pb[d]->next;
                        delete pb[d];
                        pb[d] = tmp;
                    }
                }
                cout << "couldnt reach the database!" << endl;
                return help;
            }
            nd->name = name_get;
            nd->number = num_get;
            nd->next = NULL;
            switch(name_get[0]){
                case 'A' : FLtest = 0; break;
                case 'B' : FLtest = 1; break;
                case 'C' : FLtest = 2; break;
                case 'D' : FLtest = 3; break;
                case 'E' : FLtest = 4; break;
                case 'F' : FLtest = 5; break;
                case 'G' : FLtest = 6; break;
                case 'H' : FLtest = 7; break;
                case 'I' : FLtest = 8; break;
                case 'J' : FLtest = 9; break;
                case 'K' : FLtest = 10; break;
                case 'L' : FLtest = 11; break;
                case 'M' : FLtest = 12; break;
                case 'N' : FLtest = 13; break;
                case 'O' : FLtest = 14; break;
                case 'P' : FLtest = 15; break;
                case 'Q' : FLtest = 16; break;
                case 'R' : FLtest = 17; break;
                case 'S' : FLtest = 18; break;
                case 'T' : FLtest = 19; break;
                case 'U' : FLtest = 20; break;
                case 'V' : FLtest = 21; break;
                case 'W' : FLtest = 22; break;
                case 'X' : FLtest = 23; break;
                case 'Y' : FLtest = 24; break;
                case 'Z' : FLtest = 25; break;
            }
            for(node *tmp = pb[FLtest] ; true ; tmp = tmp->next){
                if(tmp == NULL){
                    tmp = nd;
                    break;
                }
                if(tmp->next == NULL){
                tmp->next = nd;
                break;
                }
            }
        }
    }
    name_data2.close();
    num_data2.close();

    //put new name and number in their place in the array
    for(node *tmp = pb[FL] ; true ; tmp = tmp->next){
        if(tmp == NULL){
            tmp = n;
            break;
        }
        if(tmp->next == NULL){
            tmp->next = n;
            break;
        }        
    }

    //put back names in the names file and numbers in the numbers file
    name_data.open("data/names.txt", ios::out);
    num_data.open("data/numbers.txt", ios::out);
    if(name_data.is_open() && num_data.is_open()){
        for(int i = 0 ; i < 26 ; i++){
            for(node *tmp = pb[i] ; tmp != NULL || tmp->next != NULL ; tmp = tmp->next){
                name_data << tmp->name << "\n";
                num_data << tmp->number << "\n";
            }
            while(pb[i] != NULL){
                node *tmp = pb[i]->next;
                delete pb[i];
                pb[i] = tmp;
            }
        }    
    }
    name_data.close();
    num_data.close();

    //put the numbers test back in pb test
    test.open("emails/pb test.txt", ios::out);
    t =+ 1;
    test << t;
    test.close();

    cout << "name and number were added." << endl;
    help = 0;
    return help;
}

//-------------------------------------------------------------------------------------------------------------

int search(int help){
    //pointring all nodes to NULL
    for(int i = 0 ; i < 26 ; i++){
        pb[i] = NULL;
    }
    
    //get the numbers test from pb test
    int t;
    test2.open("data/pb test.txt", ios::in);
    test2 >> t;
    test2.close();
    
    //get names from names file and numbers from numbers file, put them into the array
    string name_get, num_get;
    int FLtest;
    name_data2.open("data/names.txt", ios::in);
    num_data2.open("data/numbers.txt", ios::in);
    if(name_data2.is_open() && num_data2.is_open()){
        int i = 0;
        while(!name_data2.eof() && !num_data2.eof() && i < t){
            name_data2 >> name_get;
            num_data2 >> num_get;
            i++;
            node *nd = new(node);
            if(nd == NULL){
                cout << "RAM error!" << endl;
                for(int d = 0 ; d < 26 ; d++){
                    while(pb[d] != NULL){
                        node *tmp = pb[d]->next;
                        delete pb[d];
                        pb[d] = tmp;
                    }
                }
                cout << "couldnt reach the database!" << endl;
                return help;
            }
            nd->name = name_get;
            nd->number = num_get;
            nd->next = NULL;
            switch(name_get[0]){
                case 'A' : FLtest = 0; break;
                case 'B' : FLtest = 1; break;
                case 'C' : FLtest = 2; break;
                case 'D' : FLtest = 3; break;
                case 'E' : FLtest = 4; break;
                case 'F' : FLtest = 5; break;
                case 'G' : FLtest = 6; break;
                case 'H' : FLtest = 7; break;
                case 'I' : FLtest = 8; break;
                case 'J' : FLtest = 9; break;
                case 'K' : FLtest = 10; break;
                case 'L' : FLtest = 11; break;
                case 'M' : FLtest = 12; break;
                case 'N' : FLtest = 13; break;
                case 'O' : FLtest = 14; break;
                case 'P' : FLtest = 15; break;
                case 'Q' : FLtest = 16; break;
                case 'R' : FLtest = 17; break;
                case 'S' : FLtest = 18; break;
                case 'T' : FLtest = 19; break;
                case 'U' : FLtest = 20; break;
                case 'V' : FLtest = 21; break;
                case 'W' : FLtest = 22; break;
                case 'X' : FLtest = 23; break;
                case 'Y' : FLtest = 24; break;
                case 'Z' : FLtest = 25; break;
            }
            for(node *tmp = pb[FLtest] ; true ; tmp = tmp->next){
                if(tmp == NULL){
                    tmp = nd;
                    break;
                }
                if(tmp->next == NULL){
                tmp->next = nd;
                break;
                }
            }
        }
    }
    name_data2.close();
    num_data2.close();

    //get the name and know in any index must search
    string pname;
    int FL = -1;
    cout << "name (first letter must be capital!): "; cin >> pname;
    while(FL = -1){
        switch(pname[0]){
            case 'A' : FL = 0; break;
            case 'B' : FL = 1; break;
            case 'C' : FL = 2; break;
            case 'D' : FL = 3; break;
            case 'E' : FL = 4; break;
            case 'F' : FL = 5; break;
            case 'G' : FL = 6; break;
            case 'H' : FL = 7; break;
            case 'I' : FL = 8; break;
            case 'J' : FL = 9; break;
            case 'K' : FL = 10; break;
            case 'L' : FL = 11; break;
            case 'M' : FL = 12; break;
            case 'N' : FL = 13; break;
            case 'O' : FL = 14; break;
            case 'P' : FL = 15; break;
            case 'Q' : FL = 16; break;
            case 'R' : FL = 17; break;
            case 'S' : FL = 18; break;
            case 'T' : FL = 19; break;
            case 'U' : FL = 20; break;
            case 'V' : FL = 21; break;
            case 'W' : FL = 22; break;
            case 'X' : FL = 23; break;
            case 'Y' : FL = 24; break;
            case 'Z' : FL = 25; break;
            default : FL = -1; cout << "value error!" << endl; cout << "name (first letter must be capital!): "; cin >> pname;
        }
    }

    //search name in the array
    int stest = 1;
    for(node *tmp = pb[FL] ; true ; tmp = tmp->next){
        if(tmp->name == pname){
            cout << "name found!\nname: " << pname << "\tnumber: " << tmp->number << endl;
            stest = 0;
            break;
        }
    }
    if(stest == 1){
        cout << "name couldnt found! sorry." << endl;
    }

    help = 0;
    return help;
}