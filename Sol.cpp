# solution-of-eqations-with-3-and-2-variables
The repository is made in C plus plus with minimum code and give instant performance with proper variables names and commentings
#include <iostream>
#include <vector>
using namespace std;
float determinant(vector<vector<float>>);
int main(void)
{

    vector<float> variable(3, 0), Determinant_number(4, 0);
    vector<vector<float>> Temporary_Matrix(3, vector<float>(3, 0)), Augmented_matrix(3, vector<float>(4, 0));
    int No_of_variables{3};

    cout << "Arrange eqaution in type :- " << endl
         << "(A1)X + (B1)Y + (C1)Z = (D1)" << endl
         << "(A2)X + (B2)Y + (C2)Z = (D2)" << endl
         << "(A3)X + (B3)Y + (C3)Z = (D3)" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << endl
                 << "Enter " << (char)(j + 65) << (i + 1) << " : ";
            cin >> Augmented_matrix.at(i).at(j); // Taking values of coffecient and constant term
        }
    }

    for (int k = 0, m = 0; m < 4; m++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                switch (m)
                {
                case 1:
                    if (j == 0)
                        k = 3;
                    else
                        k = j;
                    break;
                case 2:
                    if (j == 1)
                        k = 3;
                    else
                        k = j;
                    break;
                case 3:
                    if (j == 2)
                        k = 3;
                    else
                        k = j;
                    break;
                case 0:
                    k = j;
                    break;
                }
                Temporary_Matrix.at(i).at(j) = Augmented_matrix.at(i).at(k); //coping deteminants for calculaton
            }
        }

        Determinant_number.at(m) = determinant(Temporary_Matrix); //calculating determinant
    }
    if (Determinant_number.at(0) == 0)
    {
        if (Determinant_number.at(1) == 0 && Determinant_number.at(2) == 0 && Determinant_number.at(3) == 0)
        {
            if (Augmented_matrix.at(2).at(0) == 0 && Augmented_matrix.at(2).at(1) == 0 && Augmented_matrix.at(2).at(2) == 0 && Augmented_matrix.at(2).at(3) == 0)
            {
                float temp;
                No_of_variables--;
                temp = (Augmented_matrix.at(0).at(0) * Augmented_matrix.at(1).at(1)) - (Augmented_matrix.at(0).at(1) * Augmented_matrix.at(1).at(0));
                if (temp == 0)
                {
                    if ((Augmented_matrix.at(0).at(3) * Augmented_matrix.at(1).at(1)) - (Augmented_matrix.at(0).at(1) * Augmented_matrix.at(1).at(3)) == 0 && (Augmented_matrix.at(0).at(0) * Augmented_matrix.at(1).at(3)) - (Augmented_matrix.at(0).at(3) * Augmented_matrix.at(1).at(0)) == 0)
                    {
                        cout << endl
                             << "eqaution is in 2 variable and have Infinite solution";
                        return 0;
                    }
                    else
                    {
                        cout << endl
                             << "system is inconsistent";
                        return 0;
                    }
                }
                else
                {
                    variable.at(0) = ((Augmented_matrix.at(0).at(3) * Augmented_matrix.at(1).at(1)) - (Augmented_matrix.at(0).at(1) * Augmented_matrix.at(1).at(3))) / temp; //solution for equation in 2 variable
                    variable.at(1) = ((Augmented_matrix.at(0).at(0) * Augmented_matrix.at(1).at(3)) - (Augmented_matrix.at(0).at(3) * Augmented_matrix.at(1).at(0))) / temp;
                }
            }
            else
            {
                cout << "There are infinite number of solutions";
                return 0;
            }
        }
        else
        {
            cout << endl
                 << "System is inconsitant";
            return 0;
        }
    }

    if (No_of_variables == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            variable.at(i) = Determinant_number.at(i + 1) / Determinant_number.at(0);
        }
        for (char i = 0; i < 3; i++)
        {
            cout << (char)(88 + i) << " : " << variable.at(i) << endl;
        }
    }
    else
    {
        cout << endl
             << "X : " << variable.at(0) << endl
             << "Y : " << variable.at(1) << endl
             << "Z : arrbitraary";
    }
}

float determinant(vector<vector<float>> Temporary_Matrix)
{
    return ((Temporary_Matrix.at(0).at(0) * ((Temporary_Matrix.at(1).at(1) * Temporary_Matrix.at(2).at(2)) - (Temporary_Matrix.at(1).at(2) * Temporary_Matrix.at(2).at(1)))) - (Temporary_Matrix.at(0).at(1) * ((Temporary_Matrix.at(1).at(0) * Temporary_Matrix.at(2).at(2)) - (Temporary_Matrix.at(1).at(2) * Temporary_Matrix.at(2).at(0)))) + (Temporary_Matrix.at(0).at(2) * ((Temporary_Matrix.at(1).at(0) * Temporary_Matrix.at(2).at(1)) - (Temporary_Matrix.at(1).at(1) * Temporary_Matrix.at(2).at(0)))));
}
