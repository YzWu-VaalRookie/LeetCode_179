
int cmp(const void* a, const void* b)
{
    char ab[32], ba[32]; //�r���}�C�x�sa+b�Bb+a�U�۪��榡�Ƥ��e
    
    //sprintf�|�N�ǤJ����ӰѼ�*(int*)a�B*(int*)b�i��榡�Ʀ��r��A�è̷����޸�""���ƦC�A���ۦs�Jbuffer��(�pab�Bba)
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    
    return strcmp(ba, ab); //�ھ�strcmp�^�Ǫ���(1,0,-1)�A�N��ba�Pab��̪��j�p�F1�N��ba > ab�F0�N��ba = ab�F-1�N��ba < ab
    //strcmp�|�N��Ӧr���}�Cba�Bab�����C�Ӧr���q����k�v�@���j�p(����ASCII�Ȥj�p���)�A����X�{���P���r��or'\0'����C
    //�Ҧp�A30�P9�� => 9�j��30 �F30�P34�� => 34�j��30 �F 310�P39�� => 39�j��310 �F 110�P39�� => 39�j��110
    //���L���D�حn�D�A�N���ƭȵ��X�A��A�p30�B9�A�ܦ�309�P930�A��309�B930�o��Ӥ���
}

char* largestNumber(int* nums, int numsSize)
{
    qsort(nums, numsSize, 4, cmp); //�HExample2���ҡA�g�Lqsort()����A�s��nums[]�|�ƦC��[9,5,34,3,30]
    char* result = (char*)calloc(1, 1000);
    char* temp = result;
    for(int i = 0; i < numsSize; i++)
    {
        sprintf(temp, "%d", nums[i]); //�]for-loop����a�b�r���}�Ctemp[]�α��W�s��num[]�r��(�]nunm[]�ƭȳQsprintf�ন�r��)
        temp = temp + strlen(temp); //�ھڷ�U�α��W��num[]�r�ꪺ�r���ƶq���h�֭ӡAtemp���Щ��Ჾ�ʦh��
    }

    if(result[0] == '0') //�S���p�A����0�B0�� 
        return "0\0";
    
    return result;
    free(result);
}
