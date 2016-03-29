double findkth(int *a, int la, int *b, int lb, int k)
{
	if (la>lb)
		return findkth(b, lb, a, la, k);
	if (la == 0)
		return b[k - 1];
	if (k == 1)
		return a[0]<b[0] ? a[0] : b[0];

	//divide k into 2 parts
	int pa = k / 2<la ? k / 2 : la;
	int pb = k - pa;
	if (a[pa - 1] == b[pb - 1])
		return a[pa - 1];
	else if (a[pa - 1]<b[pb - 1])
		return findkth(a + pa, la - pa, b, lb, k - pa);
	else
		return findkth(a, la, b + pb, lb - pb, k - pb);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int total = nums1Size + nums2Size;
	if (total % 2 == 0)
		return (findkth(nums1, nums1Size, nums2, nums2Size, total / 2) + findkth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1)) / 2;
	else
		return findkth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
}