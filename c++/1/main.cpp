#include <iostream>  
using namespace std;  
class cube_volume  
{public:  
    void set_cube();  
    void multi_volume();  
    void show_cube();  
private:  
    int length;       
    int width;  
    int height;  
    int volume;  
};  
void cube_volume::set_cube()  
{  
    cout<<"length,width,height:";  
    cin>>length>>width>>height;  
}  
void cube_volume::multi_volume()  
{
	volume=length*width*height;  
}  
void cube_volume::show_cube()  
{
	cout<<"Volume="<<volume<<endl;  
}  
int main()  
{
	cube_volume cube[3];  
	int i;  
	for (i=0; i<3; i++) {  
	cube[i].set_cube();  
	cube[i].multi_volume();  
	cube[i].show_cube();  
	}  
	return 0;  
}  
