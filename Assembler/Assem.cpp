/*
 * Assembler main program.
 */
#include "stdafx.h"     // This must be present if you use precompiled headers which you will use.
#include <stdio.h>

#include "Assembler.h"

int main( int argc, char *argv[] )
{
    Assembler assem( argc, argv );

    // Establish the location of the labels:
    assem.PassI( );

    // Display the symbol table.
    assem.DisplaySymbolTable();

    // Output the symbol table and the translation.
    assem.PassII( );
	cout << "------------------------------------------------------------" << endl;
	system("pause");
	cout << endl;
    
    // Run the emulator on the VC3600 program that was generated in Pass II.
    assem.RunProgramInEmulator();
   
    // Terminate indicating all is well.  If there is an unrecoverable error, the 
    // program will terminate at the point that it occurred with an exit(1) call.
	cout << "------------------------------------------------------------" << endl;
	system("pause");
	return 0;

}
