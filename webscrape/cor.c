#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int N;
    cout << "Quantos termos serão inseridos? \n";
    cin >> N;
je:
    float SomaX, SomaY, MediaX, MediaY, SomaVarX, SomaVarY, SDX, SDY, Numerador, Correlacao;
    float variavelX[N], variavelY[N];
    SomaX = 0;
    SomaY = 0;
    SomaVarX = 0;
    SomaVarY = 0;
    Numerador = 0;

    for (int i = 0; i<N; i++)
    {
        cout << "<< TERMO " << (i+1) << " DE 'X'>>\n";
        cin >> variavelX[i];
        SomaX = SomaX + variavelX[i];
    }
    cout << endl;
     for (int i = 0; i<N; i++)
    {
        cout << "<<TERMO " << (i+1) << " DE 'Y'>>\n";
        cin >> variavelY[i];
        SomaY = SomaY + variavelY[i];
    }
    cout << endl;
    MediaX = SomaX/N;
    MediaY = SomaY/N;

    // VARIÂNCIA//

    for (int i = 0; i<N; i++)
    {
        SomaVarX = SomaVarX + pow((variavelX[i]-MediaX),2);
        SomaVarY = SomaVarY + pow((variavelY[i]-MediaY),2);
    }

    // DESVIO PADRÃO //

    SDX = sqrt(SomaVarX);
    SDY = sqrt(SomaVarY);
cout<<”SDX “<<SDX<<”    SDY  “<<SDY<<endl;
    // NUMERADOR //

    for (int i = 0; i<N; i++)
    {
        Numerador = Numerador + ((variavelX[i]-MediaX)*(variavelY[i]-MediaY));
    }
    Correlacao = Numerador/(SDX*SDY);
    cout << endl;
    cout << Correlacao << endl;
    if (Correlacao > 0.75 || Correlacao< -0.75)
    {
        cout << "O grau de correlação é forte. \n";
    }
    else
    {
        if (Correlacao > 0.50 || Correlacao< -0.50)
        {
             cout << "O grau de correlação é médio. \n";
        }
        else
        {
            cout << "não existe relação entre as variáveis acima. \n";
        }
    }
goto je;
system ("pause");
    return 0;
}
