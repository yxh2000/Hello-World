#include <stdio.h>

struct min_data_st
{
    int min_index;
    int min_value;
};
//递归求最小值
struct min_data_st min(int data[], int min_value, int min_index, int index, int n)
{
    if (index >= n)
    {
        struct min_data_st min_info;
        min_info.min_index = min_index;
        min_info.min_value = min_value;

        return min_info;
    }

    if (min_value > data[index])
    {
        min_value = data[index];
        min_index = index;
    }

    index+=1;
    min(data, min_value, min_index, index, n);
}
//递归排序
void sort(int *data, int j, int n)
{
    if (j >= n-1)
    {
        return;
    }

    //for (j=0; j< n-1; j++)
    {
        int index = 0;
        int temp = 0;
        struct min_data_st min_info;
        index = j;
        temp = data[j];
        //求最小值
        min_info = min(data, temp, index, j+1, n);

        //数据交换
        data[min_info.min_index] = data[j];
        data[j] = min_info.min_value;
    }
    j+= 1;
    sort(data, j, n);
}

int main()
{
    int i = 0;
    struct min_data_st min_info;
    int data[6] = {2, 1, 0, 5, 6, 3};

    //min_info = min(data, data[0], 0, 0, 6);
    sort(data, 0, 6);

    for (i=0; i<(sizeof(data)/ sizeof(data[0])); i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
