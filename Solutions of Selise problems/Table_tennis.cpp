#include<bits/stdc++.h>

using namespace std;

class team_info{
public:
    string team_name;
    double team_price,service_charge,match_fee,max_in_round;
    team_info(){

    }
    team_info(string str,double n)
    {
        team_name=str;
        team_price=n;
        service_charge = team_price*0.1;
        match_fee = (team_price-service_charge)*0.1;
        max_in_round = (team_price-service_charge-match_fee)*0.5;
    }

    double cur_earn=0.0;

    void current_earn(double group_members){ //if win cur_earn increase with max_in_round/(no of team-1)
        double each_match_val = max_in_round/(group_members-1);
            cur_earn += each_match_val;
    }

    double cur_bonus=0.0;

    void current_bonus(double bonus){//if win get the bonus
        cur_bonus +=bonus;
    }

};


int main()
{
    //freopen("team_info.txt","r",stdin);
    string str;
    double pr,total_baji=0;

    team_info *team_list[100];
    map<string,int> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str>>pr;
        total_baji += pr;
        team_list[i] = new team_info(str,pr);
        mp[str] = i;
    }
    /*int i=0;
    cout<<"team_name\t team_price\t service_charge\t match_fee\t max_in_round\n\n";
    while(i<n){
        cout<<team_list[i]->team_name<<"\t\t"<<team_list[i]->team_price;
        cout<<"\t\t"<<team_list[i]->service_charge<<"\t\t"<<team_list[i]->match_fee/((n/2)-1);
        cout<<"\t\t"<<team_list[i]->max_in_round<<"\n";
        i++;
    }*/

    int no_of_match;
    //freopen("match_result_map.txt","w",stdout);
    cin>>no_of_match;
    string s1,s2,win;
    for(int i=0;i<no_of_match;i++){
        cin>>s1>>s2>>win;
        //cout<<mp[s1]<<" "<<mp[s2]<<" "<<mp[win]<<"\n";

        team_list[mp[win]]->current_earn(n/2);
        team_list[mp[win]]->current_bonus(team_list[mp[s2]]->max_in_round/((n/2)-1));
    }
    int i=0;
    cout<<"team_name\t team_price\t service_charge\t max_in_round<\t Team_earns\tTeam_bonus\t Surely paied\t Total_earned\n\n";
    while(i<n){
        cout<<team_list[i]->team_name<<"\t\t"<<team_list[i]->team_price;
        cout<<"\t\t"<<team_list[i]->service_charge;
        cout<<"\t"<<team_list[i]->max_in_round<<"\t\t"<<team_list[i]->cur_earn;
        cout<<"\t\t"<<team_list[i]->cur_bonus;
        cout<<"\t\t"<<team_list[i]->match_fee<<"\t\t";

        double tt = team_list[i]->match_fee + team_list[i]->cur_bonus + team_list[i]->cur_earn;
        cout<<tt<<"\n\n";

        i++;
    }

    cout<<total_baji<<" ";

    for(int i=0;i<n;i++)
    {
        total_baji -= team_list[i]->cur_earn;
        total_baji -= team_list[i]->cur_bonus;
    }

    cout<<total_baji<<endl<<endl;

    // semi-final 1
    cin>>s1>>s2>>win;
    team_list[mp[win]]->cur_earn += team_list[mp[win]]->max_in_round*0.33;
    team_list[mp[win]]->cur_bonus += team_list[mp[s2]]->max_in_round*0.33;
    team_list[mp[win]]->cur_bonus += total_baji*0.125;
    total_baji-= total_baji*0.125;
    team_list[mp[win]]->max_in_round -= team_list[mp[win]]->max_in_round*0.33;

    // semi-final 2
    cin>>s1>>s2>>win;
    team_list[mp[win]]->cur_earn += team_list[mp[win]]->max_in_round*0.33;
    team_list[mp[win]]->cur_bonus += team_list[mp[s2]]->max_in_round*0.33;
    team_list[mp[win]]->cur_bonus += total_baji*0.125;
    total_baji-= total_baji*0.125;
    team_list[mp[win]]->max_in_round -= team_list[mp[win]]->max_in_round*0.33;
    //Final

    cin>>s1>>s2>>win;
    team_list[mp[win]]->cur_earn += team_list[mp[win]]->max_in_round*1.00;
    team_list[mp[win]]->cur_bonus += team_list[mp[s2]]->max_in_round*1.00;
    team_list[mp[win]]->cur_bonus += total_baji*0.5;
    team_list[mp[s2]]->cur_bonus += total_baji*0.5;
    total_baji-= total_baji*0.5;

    team_list[mp[win]]->max_in_round -= team_list[mp[win]]->max_in_round*1.00;



    i=0;
    cout<<"team_name\t team_price\t service_charge\t max_in_round<\t Team_earns\tTeam_bonus\t Surely paied\t Total_earned\n\n";
    cout<<"\n\n\n\n";
    while(i<n){
        cout<<team_list[i]->team_name<<"\t\t"<<team_list[i]->team_price;
        cout<<"\t\t"<<team_list[i]->service_charge;
        cout<<"\t"<<team_list[i]->max_in_round<<"\t\t"<<team_list[i]->cur_earn;
        cout<<"\t\t"<<team_list[i]->cur_bonus;
        cout<<"\t\t"<<team_list[i]->match_fee<<"\t\t";

        double tt = team_list[i]->match_fee + team_list[i]->cur_bonus + team_list[i]->cur_earn;
        cout<<tt<<"\n\n";

        i++;
    }


    return 0;
}
