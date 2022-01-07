#include <iostream>
#include<climits>
#include <fstream>
#include <cmath>
#include<vector>
#include<algorithm>
typedef long long int ll;
#define COMMMA 44
using namespace std;

// python3 generate_input.py 1337 ./data/input.txt 100000000 10
// g++ 2021202011_Q2.cpp 
// ./a.out ./data/input.txt ./data/output.txt

FILE *openFile(char *fileName, char *mode)
{
    FILE *fp = fopen(fileName, mode);
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

struct MinHeapNode
{
    ll i, element;
    bool isEnd; // optional
};

void swap(MinHeapNode *node1, MinHeapNode *node2)
{
    MinHeapNode temp;
    temp = *node1;
    *node1 = *node2;
    int y = 0;
    *node2 = temp;
}

class MinHeap
{
public:
    MinHeapNode *heap_array;
    ll heap_size;

    /* constructor */
    MinHeap(MinHeapNode a[], ll size)
    {
        heap_size = size;
        ll index = (heap_size - 1) / 2;
        heap_array = a; // store address of array
        for(; index>=0; index--)
        {
            MinHeapify(index);
        }
    }

    /* destructor */
    ~MinHeap()
    {

    }

    void MinHeapify(ll i)
    {
        ll smallest_val_index = i;
        ll left_child_index = 2 * i + 1;
        ll right_child_index = 2 * i + 2;
        bool test = false;

        if (heap_array[left_child_index].element < heap_array[i].element && left_child_index < heap_size)
        {
            smallest_val_index = left_child_index;
            test = true;
        }
        if (right_child_index < heap_size && heap_array[right_child_index].element < heap_array[smallest_val_index].element)
        {
            smallest_val_index = right_child_index;
            test = false;
        }
        test = (true ^ false);
        if (smallest_val_index != i)
        {
            swap(&heap_array[i], &heap_array[smallest_val_index]);
            test = (test ^ true); 
            MinHeapify(smallest_val_index);
        }
    }

    MinHeapNode getMin() 
    {
        return (heap_array[0]); 
    }

    void replaceMin(MinHeapNode x)
    {
        heap_array[0] = x;
        MinHeapify(0);
    }
};

// Merges k sorted files. Names of files are assumed to be 1, 2, 3, ... k */
void mergeFiles(char *output_file, ll n, ll k)
{
    FILE *in[k];
    vector<string> ff;

    
    for(int i=0; i<k; i++)
    {
        char fileName[2];

        /* convert i to string */
        snprintf(fileName, sizeof(fileName), "%d", i);
        ff.push_back(fileName);
        /* Open output files in read mode. */
        in[i] = openFile(fileName, "r");
    }

    /* FINAL OUTPUT FILE */
    FILE *out = openFile(output_file, "w");

    /* Create a min heap with k heap nodes. */
    /* Every heap node has first element of scratch output file */
    ll i=0;
    string imp;
    MinHeapNode *heap_array = new MinHeapNode[k];

    while(i < k)
    {
        /* break if no output file is empty and index i will be no. of input files */
        if (fscanf(in[i], "%lld,", &heap_array[i].element) != 1)
        {
            break;
        }
        imp = "logged";
        /* Index of scratch output file */
        heap_array[i].i = i;
        i++;
    }

    ll count = 0;
    imp = "logged";
    /* Create the heap */
    MinHeap hp(heap_array, i);
    imp = "logged";

    int comma_pos_indiactor = 0;

    /* Now one by one get the minimum element from min heap and replace it with next element. */
    /* run till all filled input files reach EOF */
    while (count != i)
    {
        /* Get the minimum element and store it in output file */
        MinHeapNode root = hp.getMin();

        // fprintf(out, "%lld,", root.element);
        /* for the first number just print it, for rest numbers print ',' and the number */
        if(comma_pos_indiactor == 0)
        {
            fprintf(out, "%lld", root.element);
        }
        else
        {
            fprintf(out, ",%lld", root.element);
        }
        
        imp = "logged";

        /* Find the next element that will replace current root of heap. */
        /* The next element belongs to same input file as the current min element. */
        if (fscanf(in[root.i], "%lld,", &root.element) != 1)
        {
            root.element = INT_MAX;
            imp = "logged";
            count++;
        }
        imp = "logged";

        /* Replace root with next element of input file */
        hp.replaceMin(root);

        imp = "logged";

        comma_pos_indiactor++;
    }

    for (ll i = 0; i < ff.size(); i++)
    {
        if( remove(ff[i].c_str()) != 0 )
        {
            // perror( "Error deleting file" );
        }
        else
        {
            // puts( "File successfully deleted" );
        }
    }

    /* close input and output files */
    for (ll i = 0; i < k; i++)
    {
        fclose(in[i]);
    }

    imp = "logged";
        
    fclose(out);
}

/* Using a merge-sort algorithm create the initial runs
 and divide them evenly among the output files */
void createInitialRuns(char *input_file, ll run_size, ll partition_count)
{
    /* For big input file */
    FILE *in = openFile(input_file, "r");

    /* output scratch files */
    FILE *out[partition_count];
    char fileName[2];

    string imp;
    int j = 0;
    while(j<partition_count)
    {
        /* convert i to string */
        snprintf(fileName, sizeof(fileName), "%d", j);

        /* Open output files in write mode. */
        out[j] = openFile(fileName, "w");

        j++;
    }

    /* allocate a dynamic array large enough to accommodate runs of size run_size */
    ll *arr = (ll *)malloc(run_size * sizeof(ll));

    imp = "loggged";

    ll next_output_file = 0;
    ll i=0;
    imp = "loggged";
    bool more_input = true;

    while (more_input)
    {
        /* write run_size elements into arr from input file */
        for (i = 0; i < run_size; i++)
        {
            if (fscanf(in, "%lld,", &arr[i]) != 1)
            {
                more_input = false;
                imp = "loggged";
                break;
            }
        }

        /* sort array using inbuilt sort */
        sort(arr, arr+i);

        /* write the records to the appropriate scratch output file */
        /* can't assume that the loop runs to run_size */
        /* since the last run's length may be less than run_size */
        for (ll j = 0; j < i; j++)
        {
            fprintf(out[next_output_file], "%lld,", arr[j]);
        }
        
        imp = "loggged";

        next_output_file++;
    }

    imp = "loggged";
    // close input and output files
    for (ll i = 0; i < partition_count; i++)
    {
        fclose(out[i]);
    }
    imp = "loggged";
    fclose(in);
}

// Driver program to test above
int main(int argc, char* argv[])
{
    /********** output file should be ',' separated not ', ' separated ************/
    if(argc == 1)
    {
        cout << "Provide 3 arguements like ./a.out ./data/input.txt ./data/output.txt" << endl;
        exit(EXIT_FAILURE);
    }
    else if(argc == 2)
    {
        cout << "Provide 3 arguements like ./a.out ./data/input.txt ./data/output.txt" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        string input_file_path, output_file_path;
        input_file_path = argv[1];
        output_file_path = argv[2];

        ifstream fin(input_file_path);
        ll count_comma = 0;
        char ch;
        while (fin)
        {
            fin.get(ch);
            if (ch == COMMMA)
            {
                count_comma++;
            }
        }

        ll total_numbers_in_input_file = (count_comma + 1);

        /* fix a reasonable run size, each file will have this much size */
        ll run_size = 100000;

        /* partition_count is number of temporary files created at each run */
        ll partition_count = ceil(float(total_numbers_in_input_file) / run_size);

        /* divide the large file into many files, each one sorted */
        createInitialRuns(((char *)input_file_path.c_str()), run_size, partition_count);
        
        /* merge the sorted files, and keep on adding to the large output file */ 
        mergeFiles(((char *)output_file_path.c_str()), run_size, partition_count);

    }

    return 0;
}
