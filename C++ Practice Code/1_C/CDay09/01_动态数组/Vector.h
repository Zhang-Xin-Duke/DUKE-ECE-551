// .h�� ͷ�ļ�
// �ṹ��Ķ��壬�Լ���¶�����ʹ�õĺ��� (API) ������

typedef int E;

typedef struct {
    E* elements;   // ָ��ѿռ������
    int size;	// Ԫ�صĸ���
    int capacity; // ���������
} Vector;

// API

// ���캯��
Vector* vector_create(void);
// ��������
void vector_destroy(Vector* v);

// ��ʵ��push_back����
void push_back(Vector* v, E val);
