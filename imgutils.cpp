#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
using namespace std;
struct Image {
  int mx=6;
  int my=10;
  int* points;
  void createImage(Image* img);
  void showImage(Image* img);
  void setPointImage(Image* img, int x, int y, int color);
  int getPointImage(Image* img, int x, int y);
  int testSaveToPnmFile(string fileName);
  int saveToPnmFile(Image* img, string fileName);
  int testCreateImage();
  int testGetPointImage(int x, int y);
  int testSetPointImage(int color);
  void dataImage(Image* img);
};

void Image::createImage(Image* img) {
	
    int n = mx * my;
	points = new int[n];
	for (int i = 0; i < n; i++)
		points[i] = 0;
	dataImage(img);
    
    
}
void Image::dataImage(Image* img)
{
	points[4] = 1;
	points[10] = 1;
	points[16] = 1;
	points[22] = 1;
	points[28] = 1;
	points[34] = 1;
	points[40] = 1;
	points[45] = 1;
	points[44] = 1;
	points[43] = 1;
	points[36] = 1;
}

void showImage(Image* img) {
    int transit = 0;
    for( int n =0; n < (img->mx*img->my);n++){
        if (transit != img->mx) {
            cout<<img->points[n];
            transit +=1;
        }
        else {
            
            cout << img->points[n];
            cout << "\n";
            transit = 0;
            
        }
        
        
    }

}

   

void setPointImage(Image* img,int x, int y,int color) {
    img->points[img->mx*y+x] = color;
}

int getPointImage(Image* img,int x, int y) {
  return img->points[img->mx*y+x];
  
}


void saveToPnmFile(Image* img, string fileName) {
    
    ofstream fout;
    fout.open(fileName`);
    
    int transit = 0;
    for( int n =0; n < (img->mx*img->my);n++){
        if (transit != img->mx-1) {
            fout<<img->points[n];
            transit +=1;
        }
        else {

            fout<<img->points[n];
            fout<<endl;
            transit = 0;
            
            
        }
    

    }
    
    fout.close();
}
    
    
    
int testCreateImage(){
        Image* img = new Image;
        createImage(img, 6, 10);
        if (img->mx != 6 || img->my != 10) return -1;
        for (int n =0; n<img->mx*img->my; n++){
            if (img->points[n] != 0) return -1;
            
        }
        
        return 0;
    }

int testShowImage(){
    
    Image* img = new Image;
    createImage(img, 2, 2);
    setPointImage(img, 1, 1, 123);
    if (img->points[img->mx*1+1] != 123) return -1;
    return 0;
}

int testSetPointImage(){
    Image* img = new Image;
    createImage(img, 2, 2);
    setPointImage(img,1,1,123);
    setPointImage(img,0,0,1);
    if (img->points[img->mx*1+1] != 123 || img->points[img->mx*0+0] != 1) return -1;
    return 0;
    
}




int testGetPointImage(){
    Image* img = new Image;
    createImage(img, 2, 2);
    setPointImage(img,1,1,123);
    if(getPointImage(img, 1, 1) != 123) return -1;
    return 0;
    
}

int testSaveToPnmFile(){
    Image* img = new Image;
    createImage(img, 2, 2);
    saveToPnmFile(img, "testImg.pnm");
    
    fstream f;
    f.open("testImg.pnm",ios::in);
    long file_size;
    f.seekg(0, ios::end);
    file_size = f.tellg();
    if (file_size == 0) {
        f.close();
        return -1;
    }
    f.close();
    return 0;
    
}
    

static void runTest(int( * testFunction)(),
  const std::string & testName) {
  if (testFunction() == 0)
    std::cout << "Test " << testName << " - OK" << std::endl;
  else
    std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int Image::DrawTraect() {
    Image* img = new Image;
  Ball a;
  float deltaT = 0.01;
  Node * head = new Node;
  Node * head_node = head;
  init(head);
  init(head_node);
  createImage(img, 250, 250);

  float t = 0;
  for (int i = 0; i < 250; i++) {

      if (i != 0){ move( & a, deltaT);
          setPointImage(img,int(a.x*10),int(a.y*10), 1);}
    pushNode(head, new Node);
      head_node -> val_x = a.x;
      head_node -> val_y = a.y;
    t += deltaT;
      
}
    
    saveToPnmFile(img, "traect.pnm");
  return 0;
}


int main() {
    
   SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Image img;
	int x = 1;
	int y = 4;
	int color = 0;
	if (img.testCreateImage() == -1)
		return -1;
	img.createImage(&img);
	img.showImage(&img);
	if (img.testGetPointImage(x, y) == -1)
		return -1;
	if (img.testSetPointImage(color) == -1)
		return -1;
	img.setPointImage(&img, x, y, color);
	img.showImage(&img);
	if (img.saveToPnmFile(&img, "image1.pnm") == -1)
		return -1;
	x = 2;
	y = 4;
	if (img.testGetPointImage(x, y) == -1)
		return -1;
    DrawTraect();
    
  return 0;
}
