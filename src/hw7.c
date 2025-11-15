#include "hw7.h"

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {
	//obtain the char of the mat.
	char matChar = mat->name;
	if (root == NULL)
	{
		bst_sf *new_BST = malloc(sizeof(bst_sf));
		new_BST->mat = mat;
		new_BST->left_child = NULL;
		new_BST->right_child = NULL;
		return root;
	}
	bst_sf *ptr = root;
	if((ptr->mat)->name == mat->name)
	{
	}
	while(1)
	{
		if((ptr->mat)->name < mat->name)
		{
			if(ptr->left_child==NULL)
			{
				bst_sf *new_BST = {mat,NULL,NULL};
				ptr->left_child = new_BST;
				return new_BST;
			}
			ptr = ptr -> left_child;
		}
		if((ptr->mat)->name > mat->name)
		{
			if(ptr->right_child==NULL)
			{
				bst_sf *new_BST = {mat,NULL,NULL};
				ptr->right_child = new_BST;
				return new_BST;
			}
			ptr = ptr -> right_child;
	
		}


	}

    return ptr;
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
	bst_sf *ptr = root;
	while (ptr != NULL && name != (ptr->mat)->name )
	{
		 if(name < (ptr->mat)->name){
			 ptr = ptr->left_child;
		 }
		 else if(name > (ptr->mat)->name){
			 ptr = ptr->right_child;
		 }
		 else if(name == (ptr->mat)->name) {
			 return ptr->mat;
		 }
	}	
    return ptr;
}

void free_bst_sf(bst_sf *root) {
	if(root != NULL)
	{
		free_bst_sf(root->left_child);
		free_bst_sf(root->right_child);
		free(root);
	}
		
}

matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
	if( (mat1->num_rows != mat2->num_rows)||(mat1->num_cols != mat2->num_cols))
	{
		return NULL;
	}
	matrix_sf *added_mat = malloc(sizeof(matrix_sf)+mat1->num_rows*mat1->num_cols*sizeof(int));
	added_mat-> name = 'C';
	added_mat->num_rows = mat1->num_rows;
	added_mat->num_cols = mat1->num_cols;
	for(int i = 0; i< added_mat->num_rows*added_mat->num_cols; i++){
		added_mat->values[i] = mat1->values[i] + mat2->values[i];
	}
	return added_mat;
	
       	

}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
	if( (mat1->num_rows != mat2->num_rows)||(mat1->num_cols != mat2->num_cols))
	{
		return NULL;
	}
	matrix_sf *added_mat = malloc(sizeof(matrix_sf)+mat1->num_rows*mat1->num_cols*sizeof(int));
	added_mat-> name = 'C';
	added_mat->num_rows = mat1->num_rows;
	added_mat->num_cols = mat1->num_cols;
	for(int i = 0; i< added_mat->num_rows*added_mat->num_cols; i++){
		added_mat->values[i] = mat1->values[i] * mat2->values[i];
	}
	return added_mat;
	
}

matrix_sf* transpose_mat_sf(const matrix_sf *mat) {
	matrix_sf *transposed_mat = malloc(sizeof(matrix_sf) + mat->num_rows*mat->num_cols*sizeof(int));
	transposed_mat->name = 'T';
	transposed_mat->num_rows = mat->num_cols;
	transposed_mat->num_cols = mat->num_rows;
	int tmPoint = 0;
	for(int i = 0; i < mat->num_rows; i++){ //Do for each row
		for(int j = 0; j < mat->num_cols; j++){ 
			// Scan through each column
			transposed_mat->values[tmPoint++] = mat->values[j*mat->num_rows+i];
		}
	}
	return transposed_mat;

			


}

matrix_sf* create_matrix_sf(char name, const char *expr) {
	matrix_sf *new_mat = malloc(sizeof(matrix_sf));
	//get number of rows and columns.
	char *p = expr;
	int value, n; //n represents number of characters read. 
	sscanf(p, "%d\n", &value, &n);
	new_mat->num_rows = value;
	*p+=n;
	sscanf(p, "%d\n", &value, &n);
	new_mat->num_cols = value;
	*p+=n;
	new_mat = realloc(new_mat, sizeof(matrix_sf)+new_mat->num_rows*new_mat->num_cols*sizeof(int));
	int nmPoint = 0;
	while((sscanf(p, "%d%n", &value, &n) == 1)){
			new_mat->values[nmPoint++]=value;
			p+=n;
	}
	return new_mat;
			

	
}

char* infix2postfix_sf(char *infix) {
    return NULL;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    return NULL;
}

matrix_sf *execute_script_sf(char *filename) {
   return NULL;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[]) {
    matrix_sf *m = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows*num_cols*sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows*mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows*mat->num_cols-1)
            printf(" ");
    }
    printf("\n");
}
