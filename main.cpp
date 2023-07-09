#include "Directed.h"
#include "Undirected.h"
int main()
{
	char c;
	int n, m;
	cout << "Is the graph directed: y/n" << endl;
	cin >> c;
	try
	{
		switch (c)
		{
		case 'y':
		{
			cin >> n >> m;
			if (m <= 0 || n <= 0)
				throw "invalid input";
			DirectedGraph D_graph(n, m);
			D_graph.EulerTour();
			break;
		}
		case 'n':
		{
			cin >> n >> m;
			if (m <= 0 || n <= 0)
				throw "invalid input";
			UndirectedGraph UnD_graph(n, m);
			UnD_graph.EulerTour();
			break;
		}
		default:
			throw "invalid input";

		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout <<"Unknown Eror ! " << endl;
	}

	
	return 0;
}
