class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        
        Node*ptr=NULL,*p=NULL;
        while(node1!=NULL)
        {
            ptr=node1;
            node1=node1->next;
            ptr->next=p;
            p=ptr;
        }
        node1=ptr;
        ptr=NULL,p=ptr;
        while(node2!=NULL)
        {
            ptr=node2;
            node2=node2->next;
            ptr->next=p;
            p=ptr;
        }
        node2=ptr;

     // into decending order
        ptr=NULL,p=ptr;
        if(node1==NULL)
        return node2;
        if(node2==NULL)
        return node1;
        
        if(node1->data<=node2->data)
        {
            p=node2;
            ptr=node2;
            node2=node2->next;
        }
        else
        {
            p=node1;
            ptr=node1;
            node1=node1->next;
        }
        while(node1!=NULL&&node2!=NULL)
        {
            if(node1->data>=node2->data)
            {
                ptr->next=node1;
                node1=node1->next;
            }
            else
            {
                ptr->next=node2;
                node2=node2->next;
                
            }
            ptr=ptr->next;
            
        }
        while(node1!=NULL)
        {
            ptr->next=node1;
            ptr=node1;
            node1=node1->next;
        }
         while(node2!=NULL)
        {
            ptr->next=node2;
            ptr=node2;
            node2=node2->next;
        }

      //merge 
        ptr->next=NULL;
        return p;
    }  
};

