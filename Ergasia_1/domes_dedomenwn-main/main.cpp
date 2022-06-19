#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;
using namespace std::chrono;

//Klash ylopoihshs struct
class Structure{
public:
  int num;
  string string1;
  string string2;
  string string3;
  //gia na mporesoume na dhmiourgisoume ena array typou class Structure
  //tha prepei na ftiaksoume enan dummy constructor
  Structure(){}
  Structure(int number,string s1,string s2,string s3){
    num=number;
    s1=string1;
    s2=string2;
    s3=string3;
  }
};


void gemisma_pinaka(int a[],int start,int end);
void copy_arrays(int a[],int b[],int n);
void write_file(double array[],int n,FILE *file);
void display(double array[],int n);
void swap(int *x,int *y);
int locOfSmallest(int b[],int s,int e);
void selectionSort(int b[],int n);
void bubble(int b[],int n);
void bubbleSort(int b[],int n);
void insertionSort(int b[],int n);
void mergeSort(int b[],int n );
void mergeSortRecursion(int b[],int l,int r);
void mergeSortedArrays(int b[],int l,int m,int r);
void quickSort(int b[],int left,int right);
void shellSort(int b[],int n);
void heapify(int b[], int n, int i);
void heapSort(int b[], int n);
//SYNARTHSEIS GIA THN TAKSINOMHSH TWN STRUCTS
//-------------------------------------
int str_locOfSmallest(Structure b[],int s,int e);
void str_selectionSort(Structure b[],int n);
void str_bubble(Structure b[],int n);
void str_bubbleSort(Structure b[],int n);
void str_insertionSort(Structure b[],int n);
void str_mergeSort(Structure b[],int n );
void str_mergeSortRecursion(Structure b[],int l,int r);
void str_mergeSortedArrays(Structure b[],int l,int m,int r);
void str_quickSort(Structure b[],int left,int right);
void str_shellSort(Structure b[],int n);
void str_heapify(Structure b[], int n, int i);
void str_heapSort(Structure b[], int n);

int main(){
  int array[1000];
  //pinakes stous opoious tha apothikeytoun oi xronoi taksinomhshs
  double time_selectionSort[10];
  double time_bubbleSort[10];
  double time_insertionSort[10];
  double time_mergeSort[10];
  double time_quickSort[10];
  double time_shellSort[10];
  double time_heapSort[10];
  int j=0;//index gia tous pinakes stous opoious tha apo8hkeytoun oi xronoi ekteleshs
  //TAKSINOMHSEIS AKERAIWN
  for(int i=100;i<=1000;i+=100){
    gemisma_pinaka(array,i-100,i);
    int sorted_array[i];
    copy_arrays(array,sorted_array,i);
    clock_t time;
    //Selection Sort
    time = clock();
    selectionSort(sorted_array,i);
    time = clock()-time;
    double time_taken = (double)time/(double)CLOCKS_PER_SEC;
    time_selectionSort[j]=time_taken;
    //Bubble Sort
    time = clock();
    bubbleSort(sorted_array,i);
    time = clock()-time;
    time_taken = (double)time/(double)CLOCKS_PER_SEC;
    time_bubbleSort[j]=time_taken;
    //Insertion Sort
    time = clock();
    insertionSort(sorted_array,i);
    time = clock()-time;
    time_taken=(double)time/(double)CLOCKS_PER_SEC;
    time_insertionSort[j]=time_taken;
    //Merge Sort
    time = clock();
    mergeSort(sorted_array,i);
    time = clock()-time;
    time_taken=(double)time/(double)CLOCKS_PER_SEC;
    time_mergeSort[j]=time_taken;
    //Quick Sort
    time = clock();
    quickSort(sorted_array,0,i-1);
    time = clock()-time;
    time_taken=(double)time/(double)CLOCKS_PER_SEC;
    time_quickSort[j]=time_taken;
    //Shell Sort
    time = clock();
    shellSort(sorted_array,i);
    time = clock()-time;
    time_taken=(double)time/(double)CLOCKS_PER_SEC;
    time_shellSort[j]=time_taken;
    //Heap Sort
    time = clock();
    heapSort(sorted_array,i);
    time = clock()-time;
    time_taken=(double)time/(double)CLOCKS_PER_SEC;
    time_heapSort[j]=time_taken;
    j++;
  }
  //Eggrafh xronwn ektelesewn sto arxeio data.txt
  FILE *file;
  file = fopen("data.txt","a");
  fprintf(file,"Selection Sort\n");
  write_file(time_selectionSort,10,file);
  fprintf(file,"----------------\nBubble Sort\n");
  write_file(time_bubbleSort,10,file);
  fprintf(file,"----------------\nInsertion Sort\n");
  write_file(time_insertionSort,10,file);
  fprintf(file,"----------------\nMerge Sort\n");
  write_file(time_mergeSort,10,file);
  fprintf(file,"----------------\nQuick Sort\n");
  write_file(time_quickSort,10,file);
  fprintf(file,"----------------\nShell Sort\n");
  write_file(time_quickSort,10,file);
  fprintf(file,"----------------\nHeap Sort\n");
  write_file(time_heapSort,10,file);

  //DHMIOURGIA OBJECT MESW TOU OPOIOU 
  //THA YLOPOIHTHOYN TA STRUCTS
  
  Structure array_str[100];
  //perasma tyxaiwn dedomenwn apo to arxeio rand_data.csv sto pinaka array_str
  fstream rand_data;
  rand_data.open("rand_data.csv",ios::in);
	vector<string> row2;
	for(int i=0;i<100;i++){
		row2.clear();
		//h katalhksh .clear() katharizei to vector
		string line2,word2;
		getline(rand_data,line2);
		stringstream s2(line2);
		while (getline(s2,word2,','))
			row2.push_back(word2);
    //to vector apo8hkeyei string data,ara to row2[0] pou periexei ton akeraio arithmo prepei na metatrapei apo string se int
    int a=stoi(row2[0]);
		array_str[i]=Structure(a,row2[1],row2[2],row2[3]);
	}
  //TAKSINOMISEIS TWN STRUCTS
  cout<<"TAKSINOMISEIS TWN STRUCTS"<<endl;
  //Selection Sort
  auto start=high_resolution_clock::now();
  str_selectionSort(array_str,100);
  auto stop=high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"Selection Sort:"<<duration.count()<<" microseconds."<<endl;
  //Bubble Sort
  start=high_resolution_clock::now();
  str_bubbleSort(array_str,100);
  stop=high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"Bubble Sort:"<<duration.count()<<" microseconds."<<endl;
  //Insertion Sort
  start=high_resolution_clock::now();
  str_insertionSort(array_str,100);
  stop=high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"Insertion Sort:"<<duration.count()<<" microseconds."<<endl;
  //Merge Sort
  start=high_resolution_clock::now();
  str_mergeSort(array_str,100);
  stop=high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"Merge Sort:"<<duration.count()<<" microseconds."<<endl;
  //Quick Sort
  start=high_resolution_clock::now();
  str_quickSort(array_str,0,100-1);
  stop=high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"Quick Sort:"<<duration.count()<<" microseconds."<<endl;
  //Shell Sort
  start=high_resolution_clock::now();
  str_shellSort(array_str,100);
  stop=high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"Shell Sort:"<<duration.count()<<" microseconds."<<endl;
  //Heap Sort
  start=high_resolution_clock::now();
  str_heapSort(array_str,100);
  stop=high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout<<"Heap Sort:"<<duration.count()<<" microseconds."<<endl;
  
  return 0;
}

void gemisma_pinaka(int a[],int start,int end){
  for(int i=start;i<end;i++)
    a[i]=rand()%1000001;
}

void copy_arrays(int a[],int b[],int n){
    for(int i=0;i<n;i++)
        b[i]=a[i];
}

void write_file(double array[],int n,FILE *file){
 for(int i=1;i<=n;i++)
  fprintf(file,"Plhthos akeraiwn=%d sec:%lf\n",i*100,array[i-1]);
}

void display(double array[],int n){
    for(int i=0;i<n;i++)
        cout<<array[i]<<", ";
    cout<<endl;
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int locOfSmallest(int b[],int start,int end){
    int j = start;
    for(int i=start;i<end;i++){
        if(b[i]<b[j])
            j = i;
    }
    return j;
}

void selectionSort(int b[],int n ){
    for(int i=0;i<n;i++){
        int j = locOfSmallest(b,i,n);
        swap(&b[i],&b[j]);
    }
}

void bubble(int b[],int n){
    for(int i=n-1;i>=0;i--){
        if(b[i]<b[i-1])
            swap(&b[i],&b[i-1]);
    }
}

void bubbleSort(int b[],int n){
    for(int i=0;i<n;i++){
        bubble(b,n);
    }
}

void insertionSort(int b[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>=1;j--){
            if (b[j]<b[j-1])
                swap(&b[j],&b[j-1]);
            else
                break;
        }
    }
}

void mergeSort(int b[],int n){
    mergeSortRecursion(b,0,n-1);
}

void mergeSortRecursion(int b[],int l,int r){
    if (l<r){
        int m = l+(r-l)/2;
        mergeSortRecursion(b,l,m);
        mergeSortRecursion(b,m+1,r);

        mergeSortedArrays(b,l,m,r);
    }
}

void mergeSortedArrays(int b[],int l,int m,int r){
    int left_length = m-l+1;
    int right_length = r-m;

    int temp_left[left_length];
    int temp_right[right_length];

    int i,j,k;

    for(int i=0;i<left_length;i++)
        temp_left[i] = b[l+i];
    for(int i=0;i<right_length;i++)
        temp_right[i] = b[m+1+i];

    i=0;
    j=0;
    for(k=l;k<=r;k++){
        if ((i<left_length) && (j>=right_length || temp_left[i]<=temp_right[j])){
            b[k] = temp_left[i];
            i++;
        }else {
            b[k] = temp_right[j];
            j++;
    }
  }
}

void quickSort(int b[], int left, int right){
	int i, j, x, k;

	i = left;
	j = right;
	k = (left+right) / 2;
	x = b[k];

	do {
		while (b[i] < x)
			i++;
		while (b[j] > x)
			j--;
		if (i <= j) {
			swap(&b[i], &b[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		quickSort(b, left, j);
	if (i < right)
		quickSort(b, i, right);
}

void shellSort(int b[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp = b[i];
            int j;
            for(j=i;j>=gap&&b[j-gap]>temp;j-=gap)
                b[j]=b[j-gap];
            b[j]=temp;
        }
    }
}

void heapify(int b[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && b[l] > b[largest])
        largest = l;

    if (r < n && b[r] > b[largest])
      largest = r;

    if (largest != i) {
        swap(&b[i], &b[largest]);
        heapify(b, n, largest);
    }
}

void heapSort(int b[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(b, n, i);
    for (int i = n - 1; i >= 0; i--){
        swap(&b[0], &b[i]);
        heapify(b, i, 0);
    }
  }

//SYNARTHSEIS GIA THN TAKSINOMHSH TWN STRUCTS
//-------------------------------------
int str_locOfSmallest(Structure b[],int start,int end){
    int j = start;
    for(int i=start;i<end;i++){
        if(b[i].num<b[j].num)
            j = i;
    }
    return j;
}

void str_selectionSort(Structure b[],int n ){
    for(int i=0;i<n;i++){
        int j = str_locOfSmallest(b,i,n);
        swap(&b[i].num,&b[j].num);
    }
}

void str_bubble(Structure b[],int n){
    for(int i=n-1;i>=0;i--){
        if(b[i].num<b[i-1].num)
            swap(&b[i].num,&b[i-1].num);
    }
}

void str_bubbleSort(Structure b[],int n){
    for(int i=0;i<n;i++){
        str_bubble(b,n);
    }
}

void str_insertionSort(Structure b[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>=1;j--){
            if (b[j].num<b[j-1].num)
                swap(&b[j].num,&b[j-1].num);
            else
                break;
        }
    }
}

void str_mergeSort(Structure b[],int n){
    str_mergeSortRecursion(b,0,n-1);
}

void str_mergeSortRecursion(Structure b[],int l,int r){
    if (l<r){
        int m = l+(r-l)/2;
        str_mergeSortRecursion(b,l,m);
        str_mergeSortRecursion(b,m+1,r);

        str_mergeSortedArrays(b,l,m,r);
    }
}

void str_mergeSortedArrays(Structure b[],int l,int m,int r){
    int left_length = m-l+1;
    int right_length = r-m;

    int temp_left[left_length];
    int temp_right[right_length];

    int i,j,k;

    for(int i=0;i<left_length;i++)
        temp_left[i] = b[l+i].num;
    for(int i=0;i<right_length;i++)
        temp_right[i] = b[m+1+i].num;

    i=0;
    j=0;
    for(k=l;k<=r;k++){
        if ((i<left_length) && (j>=right_length || temp_left[i]<=temp_right[j])){
            b[k].num = temp_left[i];
            i++;
        }else {
            b[k].num = temp_right[j];
            j++;
    }
  }
}

void str_quickSort(Structure b[], int left, int right){
	int i, j, x, k;

	i = left;
	j = right;
	k = (left+right) / 2;
	x = b[k].num;

	do {
		while (b[i].num < x)
			i++;
		while (b[j].num > x)
			j--;
		if (i <= j) {
			swap(&b[i].num, &b[j].num);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		str_quickSort(b, left, j);
	if (i < right)
		str_quickSort(b, i, right);
}

void str_shellSort(Structure b[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp = b[i].num;
            int j;
            for(j=i;j>=gap&&b[j-gap].num>temp;j-=gap)
                b[j].num=b[j-gap].num;
            b[j].num=temp;
        }
    }
}

void str_heapify(Structure b[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && b[l].num > b[largest].num)
        largest = l;

    if (r < n && b[r].num > b[largest].num)
      largest = r;

    if (largest != i) {
        swap(&b[i].num, &b[largest].num);
        str_heapify(b, n, largest);
    }
}

void str_heapSort(Structure b[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        str_heapify(b, n, i);
    for (int i = n - 1; i >= 0; i--){
        swap(&b[0].num, &b[i].num);
        str_heapify(b, i, 0);
    }
  }
