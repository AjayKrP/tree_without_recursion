				#include<iostream>
				#include<queue>
				#include<stack>

				using namespace std;

				class graph{
				public:
				    graph(){
				       for(int i=0;i<10;++i){
					   array[i] = nullptr;
				       }
				    }
				    graph* create_dest(int dest);
				    void AddAtFront(int src, int dest);
				    void AddAtEnd(int src, int dest);
				    graph* create_src(int src);
				    void insert( int src, int dest);
				    void print_graph(int n);
				    virtual ~graph(){
					for(int i=0;i<10;++i) {
					    delete array[i];
					}
				    }
				private:
				    int src, dest;
				    graph* next;
				    graph *array[10];
				};

				void graph::AddAtFront(int src, int dest)
				{
				    graph* temp = new graph();
				    temp -> dest = dest;

				    if(array[src]==NULL)
				    {
					array[src] = temp;
					temp->next=NULL;
				    }else{
					temp->next = array[src];
					array[src] = temp;
				    }
				}
				graph* graph::create_dest( int dest) {
				    graph* temp = new graph();
				    temp -> dest = dest;
				    temp -> next = nullptr;
				    return temp;
				}

				graph* graph::create_src(int src) {
				    graph* temp = new graph();
				    temp -> src = src;
				    temp -> next = nullptr;
				    return temp;
				}
				void graph::insert( int src, int dest) {
				    graph* temp = array[src];
				    if(array[src]== nullptr){
					array[src] = create_src(src);
					array[src]->dest = dest;
				    } else{
					while (temp->next != nullptr){
					    temp = temp->next;
					}
					/*create_dest(dest)->next = array[src];
					array[src] = create_dest(dest);*/
					temp->next = create_dest(dest);
					create_dest(dest)->next = nullptr;
				    }
				}

				void graph::AddAtEnd(int src,int  dest)
				{
				    graph* temp = new graph;
				    graph *tail = array[src];
				    if(array[src] == nullptr)
				    {
					AddAtFront(src, dest);
				    }
				    else
				    {
					temp->dest = dest;
					while(tail->next!=NULL){
					    tail=tail->next;
					}
					temp->next=NULL;
					tail->next=temp;

				    }
				}
				void graph::print_graph(int n) {
				    for(int i = 0;i < n;++i){
					while (array[i]!= nullptr){
					    std::cout<<"source :"<<array[i]->src<<" -> ";
					    std::cout<<"destination :"<<array[i]->dest<<std::endl;
					    array[i] = array[i]->next;
					}
				    }
				}

				int main(){
				int src,dest,n,k;
				    graph g,*root = nullptr;
				    std::cout<<"How many data ?";std::cin>>n;k=n;
				    while (n--){
					std::cout<<"Enter source?";std::cin>>src;
					std::cout<<"Enter destination?";std::cin>>dest;
					g.insert( src, dest);
				       // g.AddAtEnd(src, dest);
				    }
				    std::cout<<"Printing elements in graph :"<<std::endl;
				    g.print_graph(k);
				}

