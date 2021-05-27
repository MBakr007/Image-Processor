/// FCI – Programming 1 – 2018 - Assignment 3
/// Program Name:
/// Last Modification Date: 13/4/2018
/// Author1 and ID and Group: Muhammad Bakr Abdel Hafez / 20170224 / G9
/// Author2 and ID and Group: Muhammad Abdel Fattah / 20170242 / G9
/// Author3 and ID and Group: Muhammad Ashraf Badwy Moussa / 20170219 / G9
/// Teaching Assistant: Eng. Khadiga Khaled and Eng. Omar Khaled
/// Purpose:..........
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];
unsigned char Large_image[SIZE][SIZE];
int x=SIZE-1;
void BW_image();
void Invert_image ();
void Merge_images();
void Filp_image();
void Rotate_image();
void DL_image();
void Detec_image();
void Enlarge_image();
void Shrink_image();
void Shuffle_image();
void loadImage();
void loadImage1();
void saveImage();


int main()
{
    loadImage();
    while (true)
    {
        cout<<"Please select a filter to apply or 0 to exit :\n"
            <<"1- Black & White Filter.\n"
            <<"2- Invert Filter.\n"
            <<"3- Merge Filter.\n"
            <<"4- Flip Image.\n"
            <<"5- Rotate Image.\n"
            <<"6- Darken and Lighten Image.\n"
            <<"7- Detect Image Edges.\n"
            <<"8- Enlarge Image.\n"
            <<"9- Shrink Image.\n"
            <<"a- Shuffle Image.\n"
            <<"s- Save the image to a file.\n"
            <<"L- Load an image.\n"
            <<"0- Exit.\n";
        char choice;
        cout<<">>> ";
        cin>>choice;
        if (choice=='1')
        {
            BW_image();
        }
        else if (choice=='2')
        {
            Invert_image();
        }
        else if (choice=='3')
        {
            loadImage1();
            Merge_images();
        }
        else if (choice=='4')
        {
            Filp_image();
        }
        else if (choice=='5')
        {
            int num;
            cout<<"1-Rotate 90.\n"
                <<"2-Rotate 180.\n"
                <<"3-Rotate 270.\n";
            cout<<">>> ";
            cin>>num;
            if (num==1)
            {
                Rotate_image();
            }
            else if (num==2)
            {
                Rotate_image();
                Rotate_image();
            }
            else if (num==3)
            {
                Rotate_image();
                Rotate_image();
                Rotate_image();
            }
        }
        else if (choice=='6')
        {
            DL_image();
        }
        else if (choice=='7')
        {
            Detec_image();
        }
        else if (choice=='8')
        {
            Enlarge_image();
        }
        else if (choice=='9')
        {
            Shrink_image();
        }
        else if (choice=='0')
            break;
        else if (choice=='a' || choice=='A')
            Shuffle_image();
        else if (choice=='l' || choice=='L')
            loadImage();
        else if (choice=='s' || choice=='S')
        {
            saveImage();
        }
        else
            cout<<"Please enter a right number.\n";
        cout<<endl;
    }
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}


void loadImage1 () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image2);
}


void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}




void BW_image()
{
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            if ((image[i][j]+image[i][j]+image[i][j])/3 > 127)
            {
                image[i][j]=255;
                image[i][j]=255;
                image[i][j]=255;
            }
            else
            {
                image[i][j]=0;
                image[i][j]=0;
                image[i][j]=0;
            }
        }
    }
}



void Invert_image()
{
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            if (image[i][j]==0)
            {
                image[i][j]=255;
            }
            else if (image[i][j]==255)
            {
                image[i][j]=0;
            }
            else
            {
                image[i][j]=255-image[i][j];
            }
        }
    }
}




void Merge_images()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j]=(image[i][j] + image2[i][j])/2;
        }
    }
}

void Filp_image()
{
    int choice;
    cout<<"1-Horizontal.\n"
        <<"2-Vertical.\n"
        <<">>> ";
    cin>>choice;
    if (choice==2)
    {
        for (int i=0; i<SIZE; i++)
        {
            for (int j=0; j<SIZE; j++)
            {
                new_image[i][j]=image[255-i][j];
            }
        }
    }
    else if (choice==1)
    {
         for (int i=0; i<SIZE; i++)
        {
            for (int j=0; j<SIZE; j++)
            {
                new_image[i][j]=image[i][255-j];
            }
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE; j++)
        {
            image[i][j]=new_image[i][j];
        }
    }
}



void  Rotate_image()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            new_image[i][j]=image[j][x];
        }
        x--;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            image[i][j]=new_image[i][j];
        }
    }
}




void DL_image()
{
    int num;
    cout <<"1-Darken Image.\n"
         <<"2-Lighten Image.\n"
         <<">>> ";
    cin >> num;
    if (num==1)
    {
        for (int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE ; j++)
            {
                image[i][j]/=2;
            }
        }
    }
    else if (num==2)
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE ; j++)
            {
                int Index=image[i][j] + 0.5*image[i][j];
                if ( Index > 255)
                {
                    Index=255;
                }
                image[i][j] = Index;
            }
        }
    }
}



void Detec_image()
{
    BW_image();
    for (int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            if (image[i][j]==0)
            {
                if (image[i][j-1]==0 && image[i-1][j-1]==0 && image[i-1][j]==0 && image[i-1][j+1]==0 && image[i][j+1]==0 && image[i+1][j+1]==0 && image[i+1][j]==0 && image[i+1][j-1]==0)
                {
                            new_image[i][j]=1;
                }
            }
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE; j++)
        {
            if(new_image[i][j]==1)
            {
                image[i][j]=255;
            }
        }
    }
}


void Enlarge_image()
{
    int  choice;
    cout<<"1-First quarter.\n"
        <<"2-Second quarter.\n"
        <<"3-Third quarter.\n"
        <<"4-Forth quarter.\n"
        <<">>> ";
    cin >> choice;
    if(choice==1)
    {
        int num1=0 , num2=0 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {

                Large_image[i][j]=image[num1][num2];
                Large_image[i+1][j]=image[num1][num2];
                Large_image[i][j+1]=image[num1][num2];
                Large_image[i+1][j+1]=image[num1][num2];
                num2++;
            }
            num2=0;
            num1++;
        }
    }
    else if (choice==2)
    {
        int num1=0 , num2=SIZE/2 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i+1][j]=image[num1][num2];
                Large_image[i][j+1]=image[num1][num2];
                Large_image[i+1][j+1]=image[num1][num2];
                num2++;
            }
            num2=SIZE/2;
            num1++;
        }
    }
    else if (choice==3)
    {
        int num1=SIZE/2 , num2=0 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i+1][j]=image[num1][num2];
                Large_image[i][j+1]=image[num1][num2];
                Large_image[i+1][j+1]=image[num1][num2];
                num2++;
            }
            num2=0;
            num1++;
        }
    }
    else if (choice==4)
    {
        int num1=SIZE/2 , num2=SIZE/2 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i+1][j]=image[num1][num2];
                Large_image[i][j+1]=image[num1][num2];
                Large_image[i+1][j+1]=image[num1][num2];
                num2++;
            }
            num2=SIZE/2;
            num1++;
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE; j++)
        {
            image[i][j]=Large_image[i][j];
        }
    }
}




void Shrink_image()
{
    int choice , num;
    cout<<"1-shrink the image dimensions to 1/2 the original dimensions.\n"
        <<"2-shrink the image dimensions to 1/3 the original dimensions.\n"
        <<"3-shrink the image dimensions to 1/4 the original dimensions.\n"
        <<">>> ";
    cin>>choice;
    if(choice==1)
        num=2;
    else if (choice==2)
        num=3;
    else if(choice==3)
        num=4;
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            new_image[i/num][j/num]=image[i][j];
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            image[i][j]=new_image[i][j];
        }
    }
}



void Shuffle_image()
{
    int arrayOfnum[4] , x=0 , num1 , num2 , N1=0 , N2=0 , L1=SIZE/2 , L2=SIZE/2;
    cout<<">>> ";
    for(int i=0; i<4 ; i++)
    {
        cin>>arrayOfnum[i];
    }
    while (x<=3)
    {
        if(arrayOfnum[x]==1)
        {
            num1=0, num2=0;
        }
        else if(arrayOfnum[x]==2)
        {
            num1=0, num2=SIZE/2;
        }
        else if(arrayOfnum[x]==3)
        {
            num1=SIZE/2 , num2=0;
        }
        else if(arrayOfnum[x]==4)
        {
            num1=SIZE/2, num2=SIZE/2;
        }
        for(int i=N1 ; i<L1 ; i++)
        {
            for(int j=N2 ; j<L2 ; j++)
            {
                new_image[i][j]=image[num1][num2];
                num2++;
            }
            num1++;
            if(arrayOfnum[x]==1)
            {
                num2=0;
            }
            else if(arrayOfnum[x]==2)
            {
               num2=SIZE/2;
            }
            else if(arrayOfnum[x]==3)
            {
                num2=0;
            }
            else if(arrayOfnum[x]==4)
            {
                num2=SIZE/2;
            }
        }
        if(x==0)
        {
            N1=0, N2=SIZE/2 , L1=SIZE/2 , L2=SIZE;
        }
        else if (x==1)
        {
            N1=SIZE/2 , N2=0 , L1=SIZE , L2=SIZE/2;
        }
        else if (x==2)
        {
            N1=SIZE/2 , N2=SIZE/2 , L1=SIZE , L2=SIZE;
        }
        x++;
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            image[i][j]=new_image[i][j];
        }
    }
}
