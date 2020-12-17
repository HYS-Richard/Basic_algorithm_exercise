#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int vil_num;//村庄数目
    int base_radius;//基站半径
    cin >> vil_num >> base_radius;
    vector<long long> vil;//用来存储村庄位置容器
    int cache;//读入缓冲区读入cache
    for(int i = 0;i < vil_num;i++){
        cin >> cache;
        vil.push_back(cache);
    }
    sort(vil.begin(),vil.end());//输入村庄排序
    int base_num = 0;//基站数目
    int begin_vil = 0;//用来存储当前未覆盖的第一个村庄是第几个村庄
    int base_pos;//用来记录当前基站位置
    for(int i = 0;i < vil_num;i++){
        if((vil[i] - vil[begin_vil]) > base_radius){//i-1建一个基站
            base_num++;
            base_pos = i-1;
            while((vil[i] - vil[base_pos] <= base_radius)&& (i < vil_num)){
                i++;
            }
            begin_vil = i;
        }
        if((vil[vil_num-1] - vil[begin_vil] <= base_radius)&&(begin_vil != vil_num - 1)){
            base_num++;
            i = vil_num;
        }
    }

    if(begin_vil == vil_num - 1){
        base_num++;//最后一个基站单独处理
    }
    cout << base_num << endl;
    return 0;
}
