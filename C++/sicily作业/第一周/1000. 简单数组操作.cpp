#include <iostream>
using namespace std;

class MyArray 

{

public:

         MyArray();

 

         /*

                   ����һ��Ԫ��content������ĵ�position��λ�ã�ע��position��0��ʼ

                   ��ԭʼ������ 1 2 3��insert(0, 5)֮���� 5 1 2 3

                   ��������λ��������ĩβ����֮����ֱ�ӽ�Ԫ�ز��뵽����ĩβ

                   ��ԭʼ������ 1 2 3��insert(50, 6)֮���� 1 2 3 6

                   ��50��λ���ڵ�ǰ�����С֮������ֱ�Ӳ��뵽����ĩβ��Ҳ���ǵ�3��λ��

          */

         void insert(int position, int content);

         /*

                   ɾ������ĵ�position��Ԫ��

                   �������û�е�position��Ԫ�أ���ɾ���κ�Ԫ��

          */

         void deleteByPosition(int position);

         /*

                   ���������ݴ�ӡ����Ļ��ÿ��Ԫ�غ��涼����һ���Ʊ����

                   �������һ��Ԫ�ص��Ʊ��������Ҫ����

          */

         void print();

 

private:

         int contents[100];                   // ���飬�������Ԫ��

         int size;                                        // ������Ԫ�ظ���

};


         MyArray::MyArray()
         {
         	size = 0;
         } 

 
         void MyArray::insert(int position, int content)
         {
         	if (position >= 0)
         	{
         		if (position >= size)
						 {
						 	contents[size] = content;
							size++;
						 }
						 else
						 {
						 	for (int i = size; i > position; i--) contents[i] = contents[i-1];
						 	contents[position] = content;
						 	size++;
						 }
         	}
         }

         void MyArray::deleteByPosition(int position)
         {
         	if (position < size)
         	{
         		for (int i = position; i < size; i++) contents[i] = contents[i+1];
						size--;
         	}
         }

         void MyArray::print()
         {
         	if (size != 0)
         	{
         		for (int i = 0; i < size; i++)
         		cout << contents[i] << '\t';
         	}
        		cout << endl;
				 }

int main()
{
	MyArray a;
	a.insert(0,12);
	a.insert(2,34);
	a.deleteByPosition(1);
	a.print();
	return 0;
}

