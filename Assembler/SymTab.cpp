//
//		Implementation of the symbol table class.
//
#include "stdafx.h"
#include "SymTab.h"

/*
NAME

    AddSymbol - adds a new symbol to the symbol table.

SYNOPSIS

    void AddSymbol( char *a_symbol, int a_loc );

DESCRIPTION

    This function will place the symbol "a_symbol" and its location "a_loc"
    in the symbol table.
*/
void SymbolTable::AddSymbol( string &a_symbol, int a_loc )
{
    // If the symbol is already in the symbol table, record it as multiply defined.
    map<string, int>::iterator st;
    st = m_symbolTable.find( a_symbol );
    if( st != m_symbolTable.end() ) {

        st->second = multiplyDefinedSymbol;
        return;
    }
    // Record a the  location in the symbol table.
    m_symbolTable[a_symbol] = a_loc;
}

/**/
/*
void SymbolTable::DisplaySymbolTable()
NAME
	SymbolTable::DisplaySymbolTable()
SYNOPSIS
	void SymbolTable::DisplaySymbolTable()
DESCRIPTION
	Displays the Symbol Table as formatted output
RETURNS
	VOID
AUTHOR
	Arjun Bastola
DATE
	3:08 PM 5/7/2017
*/
/**/

void SymbolTable::DisplaySymbolTable() {
	cout << "Symbol Table" << endl;
	cout << "------------------------------------------------------------" << endl;
	int symbolNumber_int=0;
	cout << "Symbol#" << "\t" << "Symbol" <<  "\t" << "Location" << endl;
	for (auto const& x : m_symbolTable) {
		cout << symbolNumber_int << " \t " << x.first << " \t " << x.second << endl;
		symbolNumber_int++;
	}
	cout << "------------------------------------------------------------" << endl;

}


/**/
/*
bool SymbolTable::LookupSymbol(string &a_symbol, int &a_loc)
NAME
	SymbolTable::LookupSymbol(string &a_symbol, int &a_loc)
SYNOPSIS
	bool SymbolTable::LookupSymbol(string &a_symbol, int &a_loc)
	a_symbol -> name of the symbol
	a_loc    -> If found place the location in a_loc
DESCRIPTION
	Finds a symbol; Gives the location
RETURNS
	trur if symbol found, else false. 
AUTHOR
	Arjun Bastola
DATE
	3:08 PM 5/7/2017
*/
/**/


bool SymbolTable::LookupSymbol(string &a_symbol, int &a_loc) {
	if (m_symbolTable.find(a_symbol) == m_symbolTable.end()) {
		return false;
	}
	a_loc = m_symbolTable[a_symbol];
	return true;
}