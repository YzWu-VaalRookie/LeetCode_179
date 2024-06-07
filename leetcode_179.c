
int cmp(const void* a, const void* b)
{
    char ab[32], ba[32]; //字元陣列儲存a+b、b+a各自的格式化內容
    
    //sprintf會將傳入的兩個參數*(int*)a、*(int*)b進行格式化成字串，並依照雙引號""做排列，接著存入buffer內(如ab、ba)
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    
    return strcmp(ba, ab); //根據strcmp回傳的值(1,0,-1)，代表ba與ab兩者的大小；1代表ba > ab；0代表ba = ab；-1代表ba < ab
    //strcmp會將兩個字元陣列ba、ab中的每個字元從左到右逐一比對大小(按照ASCII值大小比較)，直到出現不同的字元or'\0'為止。
    //例如，30與9比 => 9大於30 ；30與34比 => 34大於30 ； 310與39比 => 39大於310 ； 110與39比 => 39大於110
    //不過應題目要求，將兩兩數值結合再比，如30、9，變成309與930，由309、930這兩個互比
}

char* largestNumber(int* nums, int numsSize)
{
    qsort(nums, numsSize, 4, cmp); //以Example2為例，經過qsort()比對後，新的nums[]會排列成[9,5,34,3,30]
    char* result = (char*)calloc(1, 1000);
    char* temp = result;
    for(int i = 0; i < numsSize; i++)
    {
        sprintf(temp, "%d", nums[i]); //因for-loop持續地在字元陣列temp[]銜接上新的num[]字元(因nunm[]數值被sprintf轉成字串)
        temp = temp + strlen(temp); //根據當下銜接上的num[]字串的字元數量有多少個，temp指標往後移動多少
    }

    if(result[0] == '0') //特殊情況，當比較0、0時 
        return "0\0";
    
    return result;
    free(result);
}
