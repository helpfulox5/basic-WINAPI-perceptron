#include <iostream>
#include <windows.h>
#include <vector>
#include <numeric>
using namespace std;
    vector <double> pixels;
    vector<double> weights;



    HWND hwnd = GetConsoleWindow();
    COLORREF color = RGB(255, 255,255);
    HDC hdc=GetDC(hwnd);
    COLORREF color2 = 789516;

    void sub(vector<double> data){

     for (int i = 0; i<data.size(); i++){
        if (data.at(i) == 1){
            weights.at(i) -= 1;


        }
     }




    }

   void add(vector<double> data){
     for (int i = 0; i<data.size(); i++){
        if (data.at(i) == 1){
            weights.at(i) += 1;


        }
     }




    }


void resetandscan(string expectedfire){

    pixels.clear();
int counter = 0;
COLORREF pixelcolour;
      for (int mi = 860; mi<1060; mi++){
        for (int i = 440; i<640; i++){
         GetPixel(hdc, mi, i);
          pixelcolour = GetPixel(hdc, mi, i);

         if (pixelcolour == 789516){
            pixels.push_back(0);
         }

           else{
            pixels.push_back(1);
            }
         counter++;
        }
       }

       cout << pixels.size() << endl;

   if (inner_product(pixels.begin(), pixels.end(), weights.begin(), 0) > 0 && expectedfire == "yes"){
     cout << "More than 0, expected a fire, success" << endl;
   }
   else if (inner_product(pixels.begin(), pixels.end(), weights.begin(), 0) < 0 && expectedfire == "yes"){
     cout << "Less than 0, expected a fire, failure" << endl;
     add(pixels);
   }

     else if (inner_product(pixels.begin(), pixels.end(), weights.begin(), 0) > 0 && expectedfire == "no"){
     cout << "More than 0, did not expect a fire, failure" << endl;
        sub(pixels);

   }
  else if (inner_product(pixels.begin(), pixels.end(), weights.begin(), 0) < 0 && expectedfire == "no"){

     cout << "Less than 0,did not expect a fire, success" << endl;
   }
 cout << inner_product(pixels.begin(), pixels.end(), weights.begin(), 0) << endl;
       Sleep(5000);
        system("cls");
       for (int mi = 860; mi<=1060; mi++){
        for (int i = 440; i<=640; i++){
         SetPixel(hdc, mi, i, color2);
        }
       }

       for (int mi = 860; mi<=1060; mi++){
        for (int i = 440; i<=640; i++){
         SetPixel(hdc, mi, i, color2);
        }
       }

         for (int i = 440; i<=640; i++){
        SetPixel(hdc, 860, i, color);
    }

        for (int i = 440; i<=640; i++){
        SetPixel(hdc, 1060, i, color);
    }

        for (int i = 860; i<=1060; i++){
        SetPixel(hdc, i, 640, color);
    }
            for (int i = 860; i<=1060; i++){
        SetPixel(hdc, i, 440, color);
    }





}

int main()
{
    string expectedfire;

for (int i = 0; i<40000; i++){

    weights.push_back(1);
}
    cout << "Weight Initiation complete" << endl;
    POINT p;
    Sleep(5000);

    for (int i = 440; i<=640; i++){
        SetPixel(hdc, 860, i, color);
    }

        for (int i = 440; i<=640; i++){
        SetPixel(hdc, 1060, i, color);
    }

        for (int i = 860; i<=1060; i++){
        SetPixel(hdc, i, 640, color);
    }
            for (int i = 860; i<=1060; i++){
        SetPixel(hdc, i, 440, color);
    }


while (true){
    if(GetAsyncKeyState(VK_CONTROL)){
     if(GetCursorPos(&p)){};
     SetPixel(hdc,p.x,p.y, color);
    }
    if (GetAsyncKeyState(VK_SHIFT)){
        cin >> expectedfire;
        resetandscan(expectedfire);

    }


}

    return 0;
}
