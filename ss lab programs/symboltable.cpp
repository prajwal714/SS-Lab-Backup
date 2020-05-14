// C++ program to implement Symbol Table 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 
map<string,int> ma;
int c=0;
class Node { 

	string identifier, scope, type; 
	int lineNo; 
	Node* next; 

public: 
	Node() 
	{ 
		next = NULL; 
	} 

	Node(string key, string value, string type, int lineNo) 
	{ 
		this->identifier = key; 
		this->scope = value; 
		this->type = type; 
		this->lineNo = lineNo; 
		next = NULL; 
	} 

	void print() 
	{ 
		cout << "Identifier's Name:" << identifier 
			<< "\nType:" << type 
			<< "\nScope: " << scope 
			<< "\nLine Number: " << lineNo << endl; 
	} 
	friend class SymbolTable; 
}; 

class SymbolTable { 
	Node* head[MAX]; 

public: 
	SymbolTable() 
	{ 
		for (int i = 0; i < MAX; i++) 
			head[i] = NULL; 
	} 

	int hashf(string id); // hash function 
	bool insert(string id, string scope, 
				string Type, int lineno); 

	string find(string id); 

	bool deleteRecord(string id); 

	bool modify(string id, string scope, 
				string Type, int lineno); 
}; 

// Function to modify an identifier 
bool SymbolTable::modify(string id, string s, 
						string t, int l) 
{ 
	int index = hashf(id); 
	Node* start = head[index]; 

	if (start == NULL) 
		return "-1"; 

	while (start != NULL) { 
		if (start->identifier == id) { 
			start->scope = s; 
			start->type = t; 
			start->lineNo = l; 
			return true; 
		} 
		start = start->next; 
	} 

	return false; // id not found 
} 

// Function to delete an identifier 
bool SymbolTable::deleteRecord(string id) 
{ 
	int index = hashf(id); 
	Node* tmp = head[index]; 
	Node* par = head[index]; 

	// no identifier is present at that index 
	if (tmp == NULL) { 
		return false; 
	} 
	// only one identifier is present 
	if (tmp->identifier == id && tmp->next == NULL) { 
		tmp->next = NULL; 
		delete tmp; 
		return true; 
	} 

	while (tmp->identifier != id && tmp->next != NULL) { 
		par = tmp; 
		tmp = tmp->next; 
	} 
	if (tmp->identifier == id && tmp->next != NULL) { 
		par->next = tmp->next; 
		tmp->next = NULL; 
		delete tmp; 
		return true; 
	} 

	// delete at the end 
	else { 
		par->next = NULL; 
		tmp->next = NULL; 
		delete tmp; 
		return true; 
	} 
	return false; 
} 

// Function to find an identifier 
string SymbolTable::find(string id) 
{ 
	int index = hashf(id); 
	Node* start = head[index]; 

	if (start == NULL) 
		return "-1"; 

	while (start != NULL) { 

		if (start->identifier == id) { 
			start->print(); 
            cout<<"\n\n";
			return start->scope; 
		} 

		start = start->next; 
	} 

	return "-1"; // not found 
} 

// Function to insert an identifier 
bool SymbolTable::insert(string id, string scope, 
						string Type, int lineno) 
{ 
    ma[id]=c;
    c++;
	int index = hashf(id); 
	Node* p = new Node(id, scope, Type, lineno); 

	if (head[index] == NULL) { 
		head[index] = p; 
		cout << "\n"
			<< id << " inserted"; 

		return true; 
	} 

	else { 
		Node* start = head[index]; 
		while (start->next != NULL) 
			start = start->next; 

		start->next = p; 
		cout << "\n"
			<< id << " inserted"; 

		return true; 
	} 

	return false; 
} 

int SymbolTable::hashf(string id) 
{ 
    return ma[id];
	// int asciiSum = 0; 

	// for (int i = 0; i < id.length(); i++) { 
	// 	asciiSum = asciiSum + id[i]; 
	// } 

	// return (asciiSum % 100); 
} 

// Driver code 
int main() 
{ 
	SymbolTable st; 
	string check; 
    cout<<"SYMBOL TABLE\n";
    string flag = "Y";
    int choice;
    string id,scope,type;
    int lineno;
    while(flag=="Y")
    {
        cout<<"\n 1-Insert \n 2-Find \n 3-Modify \n 4-Delete \n";
        cout<<"\nEnter Choice: ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Identifier: ";cin>>id;
            cout<<"Scope: ";cin>>scope;
            cout<<"Type: ";cin>>type;
            cout<<"LineNo: ";cin>>lineno;

            if (st.insert(id,scope,type,lineno)) 
                cout << " - successfully\n\n"; 
            else
                cout << "\nFailed to insert\n\n";
        }
        else if(choice==2)
        {
            cout<<"Identifier: ";cin>>id;
            check = st.find(id); 
            if (check != "-1") 
                cout << "\n"; 
            else
                cout << "\nIdentifier Not Present\n\n"; 
        }
        else if(choice==3)
        {   
            cout<<"Identifier: ";cin>>id;
            cout<<"Scope: ";cin>>scope;
            cout<<"Type: ";cin>>type;
            cout<<"LineNo: ";cin>>lineno;

            if (st.modify(id,scope,type,lineno)) 
                cout << "\nNumber Identifier updated\n\n"; 
        }
        else if(choice == 4)
        {
            cout<<"Identifier: ";
            cin>>id;
            if (st.deleteRecord(id)) 
                cout << "if Identifier is deleted\n"; 
            else
                cout << "\nFailed to delete\n"; 
        }
        cout<<"DO YOU WISH TO CONTINUE Y/N: ";
        cin>>flag;
    }
	return 0; 
} 
