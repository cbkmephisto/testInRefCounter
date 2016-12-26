/*
 * Copyright (c) 2016 Hailin Su, ISU NBCEC
 *
 * This file is part of testInRefCounter.
 *
 * testInRefCounter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * testInRefCounter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Lesser Public License
 * along with testInRefCounter. If not, see <http://www.gnu.org/licenses/>.
 */

//
//  testInRefCounter.cpp
//  libHailins
//
//  Created by Hailin SU on 2/12/14 at iastate.
//

#include "testInRefCounter.h"

using namespace std;

int main (const int argc, char** argv)
{
    if(argc<3)
    {
        cout << endl;
        cout << "You gave " << argc-1 << " parameters. However, we only accept >= 2." << endl << endl;
        cout << "Usage:" << endl << endl << argv[0] << " REF_file TST_file(s) *" << endl << endl;
        cout << "This program counts how many entries in TST_file were in REF_file." << endl << endl;
        cout << "For efficiency, we strongly recommend setting smaller file as REF, i.e. as 1st parameter." << endl << endl;
        cout << "If given 2 parameters, the IDs in common will be displayed on screen." << endl << endl;
        exit (-1);
    }

    ifstream infs;
    infs.open(argv[1]);
    if(!infs)
    {
        cerr << "Reference file " << argv[1] << " could not be open to read." << endl;
        exit (-2);
    }

    set<string> setRef;
    string stmp;
    //cout << " + reading ref" << endl;
    while(infs >> stmp)
        setRef.insert(stmp);

    cerr << setfill(' ') << setw(16) << setRef.size() << " in REF " << argv[1] << endl;
    infs.close();

    vector<string> matchingIDs;
    for(unsigned i=2; i<argc; ++i)
    {
        infs.open(argv[i]);
        if(!infs)
        {
            cerr << "Test file " << argv[i] << " could not be open to read." << endl;
            exit (-3);
        }

        //cout << " + testing" << endl;
        unsigned count(0), tstC(0);
        while(infs >> stmp)
        {
            ++tstC;
            if(setRef.find(stmp)!=setRef.end())
            {
                ++count;
                // OPTIONAL: output matching or unmatched here
                if(argc==3)
                    matchingIDs.push_back(stmp);
            }
        }
        cerr << right << setfill(' ') << setw(16) << tstC << " in TST " << left << setw(48) << argv[i];
        cerr << setfill(' ') << setw(10) << count << setw(10) << " MATCHES" << endl;
        infs.close();
    }

    if(argc==3)
    {
        for(unsigned i=0; i<matchingIDs.size(); ++i)
            cout << matchingIDs[i] << endl;
    }
}
