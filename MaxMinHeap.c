
void build_minheap(int Arr[], int N)
{
	for (int i = N / 2; i >= 1; i--)
		min_heapify(Arr, i, N);
}

void min_heapify(int Arr[], int i, int N)
{
	int left = 2 * i;
	int right = 2 * i + 1;
	int smallest;
	if (left <= N && Arr[left] < Arr[i])
		smallest = left;
	else
		smallest = i;
	if (right <= N && Arr[right] < Arr[smallest])
		smallest = right;
	if (smallest != i) {
		int temp = Arr[i];
		Arr[i] = Arr[smallest];
		Arr[smallest] = temp;
		min_heapify(Arr, smallest, N);
	}
}

void build_maxheap(int Arr[], int N)
{
	for (int i = N / 2; i >= 1; i--)
		max_heapify(Arr, i, N);
}

void max_heapify(int Arr[], int i, int N)
{
	int left = 2 * i;
	int right = 2 * i + 1;
	int largest;
	if (left <= N && Arr[left] > Arr[i])
		largest = left;
	else
		largest = i;
	if (right <= N && Arr[right] > Arr[largest])
		largest = right;
	if (largest != i) {
		int temp = Arr[i];
		Arr[i] = Arr[largest];
		Arr[largest] = temp;
		max_heapify(Arr, largest, N);
	}
}