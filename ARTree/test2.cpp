#include <iostream>
#include "art.h"
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

/*
int main(int argc,char **argv){
      art_tree *new_art = new art_tree; 
      init_art_tree(new_art);
      unsigned char a[11]={'a','b','c','d','e','f','g','h','i','j','\0'},c[11]="dsdwea";
      int *b=new int,*t=new int;
      *b=10;
      *t=111;
      art_insert(new_art,a,11,b);
      art_insert(new_art,c,11,t);
      int *d=new int,*e=new int;
      d=(int *)art_search(new_art,a,11);
      e=(int *)art_search(new_art,c,11);
      cout<<"d="<<*d<<endl;
      cout<<"e="<<*e<<endl;
      art_tree_destroy(new_art);
    
    return 0;
}
*/
int main(int argc,char **argv){
    if(argc < 3){
      cerr << "Usage: " << argv[0] << " path & numData" << endl;
      exit(1);
    }
    art_tree *new_art = new art_tree; 
    init_art_tree(new_art);
    char path[32];
    strcpy(path, argv[1]);
    int numData = atoi(argv[2]);
    string** keys = new string*[numData];
    int **values = new int*[numData];
    int **value_test = new int*[numData];
    for(int i=0;i<numData;i++){
      keys[i]=new string;
      values[i]=new int;
      value_test[i]=new int;
    }
    ifstream ifs;
    ifs.open(path);
    if (!ifs){
      cerr << "No file." << endl;
      exit(1);
    }
    else{
      for(int i=0; i<numData; i++){
        ifs >> *keys[i];
        *values[i]=2*i+1;
        }
      ifs.close();
      cout << path << " is used." << endl;
    }
    cout << "Start Insertion" << endl;
    for(int i=0; i<numData; i++){
		  art_insert(new_art,(const unsigned char *)keys[i],8,values[i]);
      cout<<"keys["<<i<<"] is:"<<*keys[i]<<endl;
      cout<<"values["<<i<<"] is:"<<*values[i]<<endl;
	  }
    for(int i=0;i<numData;i++){
      value_test[i]=(int *)art_search(new_art,(const unsigned char *)keys[i],8);
    }
    bool is_true=true;
    for(int i=0;i<numData;i++){
      if(*value_test[i]!=2*i+1){
         is_true=false;
         cout<<*value_test[i]<<endl;
      }
    }
    if(is_true){
      cout<<"True"<<endl;
    }else{
      cout<<"false"<<endl;
    }


  return 0;
}