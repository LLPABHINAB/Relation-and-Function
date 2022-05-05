#include <iostream>
#include <vector>


using namespace std;

vector<pair<int, int>> Relation; // Decleareing the Variable..
vector<int> set_A;
vector<int> set_B;
int nA, nB, nR;
bool flag = false, Identity_rela = false, Reflexive_rela = false, Symmetric_rela = false, Transitive_rela = false;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Search_pair(int a,int b) // These Function find if there is any pair (b,a) present in the Relation.
{
    for(int i = 0;i < nR;i++)
    {
        if(Relation.at(i).first == a && Relation.at(i).second == b)
            return true;
    }
    return false;
}

bool Ele_finder(int a) // This Function Check if the Function is present in their Respective Sets...s
{
    for(int i = 0;i < nA;i++)
    {
        if(a == set_A.at(i))
            return true;
    }
    return false;
    
}

bool Pair_Finder(int a, int b, int index)
{
    // This Function find the Pair in the Given Relation and helps in checking if the Relation doesn't have duplicate pairs..

    for(int i = 0;i < nR;i++)
    {
        if(i == index)
            continue;
        if(i != index and Relation.at(i).first == a and Relation.at(i).second == b) // Returns True if the Relation have duplicate pair.
            return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    // Input Part for All set involved....
    cout << "Enter the Cardinality of Set A : ";
    cin >> nA;

    cout << "Enter the Elements of the set A : ";
    for(int i = 0;i < nA;i++) {
        int temp; cin >> temp;
        set_A.push_back(temp);
    }

    nB = nA;
    for(int i = 0;i < nB;i++) {
        set_B.push_back(set_A[i]);
    }
    // End of Input for all  Set Involved...

    cout << "Enter the Cardinality of Relation(R) : ";
    cin >> nR;

    // As number of relation can never br greated than it  n(set_A) * n(set_B)...
    if(!((nA * nB) >= nR))
    {
        cout << "As the Number pf relation cannot exceed " << (nA * nB) << ".\n\nProgram is terminated due to error.\n";
        return 0;
    }

    cout << "\nAnd give the input of the Relation in Roaster Format\n{(a,b),(b,c),....} : ";
    for(int i = 0;i < nR;i++)
    {
        int first, second; cin >> first >> second; 
        Relation.push_back(make_pair(first, second));
    }

    // Printing the Relation these has input....
    cout << "{ ";
    for(int i = 0;i < nR;i++)
    {
        cout << "("<<Relation.at(i).first << "," << Relation.at(i).second << ") ";
    }
    cout << "}\n";
    /// End for Printing the Relation..
    ///////////////////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////////////////
    // Loginc Part for Checking if the Given relation by the User is Valid or Not..
    /*
        --
            A Given relation is Valid if Relation.at(i).first contains all  the elements of setA only ...
            No pair in the Given relation be repeated.
        --    

    */
    // Relation is define from A -> B;
    for(int i = 0;i < nR;i++)
    {
        int Ele = Relation.at(i).first;
        if(!Ele_finder(Ele))
        {
            cout << "Relation is improper.\nAs Element " << Ele << " is not in Set A!!!!\n";
            return 0;
        }
    }
    for(int i = 0;i < nR;i++)
    {
        int Ele = Relation.at(i).second;
        if(!(Ele))
        {
            cout << "Relation is improper.\nAs Element " << Ele << " is not in Set A!!!!\n";
            return 0;
        }       
    }

    // Checking for the Repetation of the Pair in the Relation..
    for(int i = 0;i < nR;i++)
    {
        int a = Relation.at(i).first;
        int b = Relation.at(i).second;

        if(Pair_Finder(a,b,i))
        {
            cout << "Relation is improper.\nAs Pair (" << a << "," << b << ") is  Repeated.\n";
            return 0;
        }
    }

    ///// End For checking for a Valid Relation...
    ///////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////////////////////
    // testing for Identity Relation...
    cout << "\n\n";
    for(int i = 0; i < nR;i++)
    {
        int a = Relation.at(i).first;
        int b = Relation.at(i).second;
        if(a != b) {
            flag = true;
            cout << "Non-Identity Relation.\n";
            break;
        }
    }
    if(!flag) {
        Identity_rela = true;
        cout << "Identity Relation.\n";
    }
    flag = false;
    /// End of the Logic Part...
    ///////////////////////////////////////////////////////////////////////////////////////////



    // Login Part for Checking if the Relation is Symmetric Relation or not...
    ///////////////////////////////////////////////////////////////////////////////////////////
    for(int i = 0;i < nR;i++)
    {
        int a = Relation.at(i).first;
        int b = Relation.at(i).second;

        if(!Search_pair(b,a))
        {
            flag = true;
            cout << "\nNon-Symmetric Relation.\n";
            break;
        }
    }
    if(!flag) {
        Symmetric_rela = true;
        cout << "\nSymmetric Relation.\n";
    }

    flag = false;
    // End for Testing the if the function is Symmetric or not...
    ///////////////////////////////////////////////////////////////////////////////////////////
    


    // Testing for Reflexive Relation....
    ///////////////////////////////////////////////////////////////////////////////////////////
    if (Identity_rela) {
        Reflexive_rela = true;
        cout << "Reflexive Relation.\n";
    }
    else {
        for(int i = 0;i < nA;i++)
        {
            int a = set_A.at(i);
            if(!Search_pair(a, a))
            {
                cout << "Non-Reflexive Relation.\n";
                flag = true;
                break;
            }
        }
        if (!flag) {
            Reflexive_rela = true;
            cout << "Reflexive Relation.\n";
        }   
    }

    flag = false;    
    // End of Logic Part...
    ///////////////////////////////////////////////////////////////////////////////////////////
    


    // Testing for Transitive Relation....
    ///////////////////////////////////////////////////////////////////////////////////////////
    
    for(int i = 0;i < Relation.size();i++)
    {
        int a1 = Relation.at(i).first;
        int b1 = Relation.at(i).second;
        for(int i = 0;i < Relation.size();i++)
        {
            int a2 = Relation.at(i).first;
            int b2 = Relation.at(i).second;
            if(b1 == a2)
            {
                if(!Search_pair(a1, b2))
                {
                    flag = true;
                    break;
                }
                
            } 
        }
        if(flag)
            break;
    }

    if(!flag) {
        Transitive_rela = true;
        cout << "Transitive Relation.\n";
    }
    else
        cout << "Non-Transitive Relation.\n";

    flag = false;
    ///////////////////////////////////////////////////////////////////////////////////////////
    

    // Checking the Equivalance in a relation..

    if(Reflexive_rela and Symmetric_rela and Transitive_rela)
        cout << "Equivalance Relation.\n";
    else
        cout << "Non-Equivalance Relation.\n";
    return 0;
}