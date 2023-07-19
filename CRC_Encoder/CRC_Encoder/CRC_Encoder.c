// CRC-8 Encoder
#include<stdio.h>
#include<string.h>

int main() 
{
	printf("CRC-8 ���ڴ� (�Է� 16-bit, ��� 24-bit)\n");
	while (1)
	{


		char input_D[17] = { 0 };
		int input_D_modify_into_number[24] = { 0, };
		int Divisor_G[9] = { 1,0,0,0,0,0,1,1,1 };
		char result[25] = { 0 };

		
		printf("�Է�: ");
		scanf("%s", input_D);
		//printf("input_D_modify_into_number: ");//�׽�Ʈ�� ���� �ڵ�
		for (int i = 0; input_D[i]; i++) {

			//�Է¹��� ���ڿ� input_D�� ����� ���Ǽ��� ���� int������ ��ȯ�ϴ� ����
			input_D_modify_into_number[i] = input_D[i] - '0';
			//printf("%d", input_D_modify_into_number[i]);//�׽�Ʈ�� ���� �ڵ�

		}
		//printf("\n");//�׽�Ʈ�� ���� �ڵ�


		for (int i = 0; i < 16; i++) {
			//division�� �������� n-k��ŭ shifit
			//n=24,k=16
			//division�� �� 8��ŭ �������� shift �Ǿ��ٰ� �����ϰ�
			//�� ���ʺ��� Ȯ���Ͽ� ��Ʈ�� 1�� ���� Ȯ���ϸ� Divisor_G�� ������ modulo 2 arithmetic �� xor������ ���� �ٲ� division�� ����ؼ� �����ϴµ�
			//�ش� ������ Q�� ��Ʈ�� �ִ��� ���� �� ���� ���ü� �ִ� �ִ��� Ƚ�� (k) ���� �ݺ��Ͽ� �������� ���Ѵ�.
			if (input_D_modify_into_number[i] == 1) {
				for (int j = 0; j < 9; j++) {
					input_D_modify_into_number[i + j] = Divisor_G[j] ^ input_D_modify_into_number[i + j];
				}
			}
			/*
			//�׽�Ʈ�� ���� �ڵ�
			printf("modulo 2 arithmetic �� D: ");
			for (int k = 0; k < 24; k++) {
				printf("%d", input_D_modify_into_number[k]);

			}
			printf("\n");
			*/

		}

		/*
		////////////////////�׽�Ʈ ���//////////////////////////
		char result_for_test[26] = { 0 };// ���� �ϳ� ����
		sprintf(result_for_test, "%s %d%d%d%d%d%d%d%d", input_D, input_D_modify_into_number[16], input_D_modify_into_number[17], input_D_modify_into_number[18], input_D_modify_into_number[19],
			input_D_modify_into_number[20], input_D_modify_into_number[21], input_D_modify_into_number[22], input_D_modify_into_number[23]);
		printf("���(���� ���� �׽�Ʈ��): %s\n", result_for_test);
		*/

		//���� ���ü� �ִ� �ִ��� Ƚ�� (k) ���� �ݺ��Ͽ� ���� division�� �������� �ȴ�. �Ʒ��� ������ division�� remainder�� ��ġ�� �����̴�.
		sprintf(result, "%s%d%d%d%d%d%d%d%d", input_D, input_D_modify_into_number[16], input_D_modify_into_number[17], input_D_modify_into_number[18], input_D_modify_into_number[19],
			input_D_modify_into_number[20], input_D_modify_into_number[21], input_D_modify_into_number[22], input_D_modify_into_number[23]);
		printf("���: %s\n", result);
	}
	return 0;
}