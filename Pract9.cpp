// Pract9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>

using namespace std;


wchar_t word[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";
wchar_t excel[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE";
wchar_t paint[] = L"C:\\WINDOWS\\system32\\mspaint.exe";
wchar_t notepad[] = L"C:\\WINDOWS\\system32\\notepad.exe";

//wchar_t process[] = L"C:\\Users\\st310-03\\Desktop\\Pract9\\x64\\Debug\\schetchic1.exe";
wchar_t process[] = L"x64\\Debug\\schetchic1.exe";

vector<PROCESS_INFORMATION> wordProcess;
vector<PROCESS_INFORMATION> excelProcess;
vector<PROCESS_INFORMATION> paintProcess;
vector<PROCESS_INFORMATION> notepadProcess;

PROCESS_INFORMATION counter;

bool working = false;




void Create(wchar_t processName[],char name)
{

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);


	//if (!CreateProcess(processName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	//{
	//	cout << "процесс не создался. Ошибка:" << GetLastError() << endl;
	//	_getch();
	//}
	switch (name)
	{
		case 'w':
		{

			wchar_t wordWithParam[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE /x";

			if (!CreateProcess(NULL, wordWithParam, NULL, NULL, FALSE,
				CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
			{
				cout << "Ошибка: " << GetLastError() << endl;
				_getch();
			}

			wordProcess.push_back(pi);


			break;
		}

		case 'e':
		{

			wchar_t excelWithParam[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE /e";

			if (!CreateProcess(NULL, excelWithParam, NULL, NULL, FALSE,
				CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
			{
				cout << "Ошибка: " << GetLastError() << endl;
				_getch();
			}

			excelProcess.push_back(pi);


			break;
		}

		case 'p':
		{

			if (!CreateProcess(processName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
			{
				cout << "процесс не создался. Ошибка:" << GetLastError() << endl;
				_getch();
			}

			paintProcess.push_back(pi);


			break;
		}

		case 'n':
		{

			if (!CreateProcess(processName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
			{
				cout << "процесс не создался. Ошибка:" << GetLastError() << endl;
				_getch();
			}

			notepadProcess.push_back(pi);


			break;
		}
		default:
		{

			if (!CreateProcess(processName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
			{
				cout << "процесс не создался. Ошибка:" << GetLastError() << endl;
				_getch();
			}
			else
			{
				counter = pi;

				working = true;
			}
			break;
		}
	}
}

void Terminate(char app)
{
	


	PROCESS_INFORMATION smh_process;
	switch (app)
	{
	case 'w':
	{
		if (wordProcess.empty())
		{
			cout << "нечего завершать" << endl;
			return ;
		}

		smh_process = wordProcess.back();
		
		BOOL t;
		
		t = TerminateProcess(smh_process.hProcess, 1);
		if (t) {
			CloseHandle(smh_process.hThread);

			CloseHandle(smh_process.hProcess);
			wordProcess.pop_back();
		}
		else {
			cout << GetLastError() << endl; 
			cin.get();
		}


		break;
	}

	case 'e':
	{

		if (excelProcess.empty())
		{
			cout << "нечего завершать" << endl;
			return;
		}

		smh_process = excelProcess.back();
		TerminateProcess(smh_process.hProcess, 1);

		CloseHandle(smh_process.hThread);

		CloseHandle(smh_process.hProcess);
		excelProcess.pop_back();

		break;
	}

	case 'p':
	{


		if (paintProcess.empty())
		{
			cout << "нечего завершать" << endl;
			return;
		}

		smh_process = paintProcess.back();
		TerminateProcess(smh_process.hProcess, 1);

		CloseHandle(smh_process.hThread);

		CloseHandle(smh_process.hProcess);
		paintProcess.pop_back();

		break;
	}

	case 'n':
	{

		if (notepadProcess.empty())
		{
			cout << "нечего завершать" << endl;
			return;
		}

		smh_process = notepadProcess.back();
		TerminateProcess(smh_process.hProcess, 1);

		CloseHandle(smh_process.hThread);

		CloseHandle(smh_process.hProcess);

		notepadProcess.pop_back();
		break;
	}
	default:
	{
		smh_process = counter;
		TerminateProcess(smh_process.hProcess, 1);

		CloseHandle(smh_process.hThread);

		CloseHandle(smh_process.hProcess);

		working = false;

		break;
	}
		break;
	}
}

void checker()
{
	if (wordProcess.empty() && excelProcess.empty() && paintProcess.empty() && notepadProcess.empty() && working)
	{
		char app = 'z';

		Terminate(app);

	}
}

int main()
{
	setlocale(0, "ru");
	int index;

	while (true)
	{



		system("cls");
		index = 0;

		cout << "Выберите действие\n" << endl;

		cout << "1.создать ворд" << endl;
		cout << "2.создать эксель" << endl;
		cout << "3.создать пеинт" << endl;
		cout << "4.создать блокнот" << endl;
		
		cout << "" << endl;

		cout << "5.закрыть последний ворд" << endl;
		cout << "6.закрыть последний эксель" << endl;
		cout << "7.закрыть последний пеинт" << endl;
		cout << "8.закрыть последний блокнок" << endl;

		cin >> index;


		switch (index)
		{

		case 1:
		{
			char app = 'w';
			Create(word,app);
			
			if (!working)
			{
				char app = 'z';
				Create(process, app);
			}

			break;
		}
		case 2:
		{
			char app = 'e';
			Create(excel, app);
			
			if (!working)
			{
				char app = 'z';
				Create(process, app);
			}

			break;

		}
		case 3:
		{
			char app = 'p';
			Create(paint, app);

			if (!working)
			{
				char app = 'z';
				Create(process, app);
			}

			break;

		}
		case 4:
		{
			char app = 'n';
			Create(notepad, app);

			if (!working)
			{
				char app = 'z';
				Create(process, app);
			}

			break;
		}
		case 5:
		{
			char app = 'w';
			Terminate(app);
			checker();
			break;
		}
		case 6:
		{
			char app = 'e';
			Terminate(app);
			checker();
			break;

		}
		case 7:
		{
			char app = 'p';
			Terminate(app);
			checker();
			break;

		}
		case 8:
		{
			char app = 'n';
			Terminate(app);
			checker();
			break;
		}
		default:

			break;
		}
	}
}

