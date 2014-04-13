var all_tasks = new Object(); 
var id = 0;

function addToDo()
{
	var text;
	var task;
	var	list = document.getElementById('ft_list');
	var to_delete;
	var note = prompt('Please enter new task: ', 'Example: make Marvin shut up');
	
	all_tasks[id] = note;
	for (i in all_tasks)
	{
		to_delete = document.getElementById(i);
		if (to_delete != null)
			list.removeChild(to_delete);
	}
	var j = id;
	while (j > -1)
	{
		if (all_tasks[j])
		{
			text = document.createTextNode(all_tasks[j]);
			task = document.createElement('div');
			task.setAttribute('id', j);
			task.setAttribute('onclick', 'deleteTask(this)');
			task.setAttribute('style', 'width: 100%; color: white; background-color: rgb(200,50,50); margin: 0px; padding: 10px; border-bottom: 1px solid black;');
			task.appendChild(text);
			list.appendChild(task);
		}
		--j;
	}
	++id;
}

function deleteTask(elem)
{
	var to_delete = document.getElementById(elem.id);
	var list = document.getElementById('ft_list');
	list.removeChild(to_delete);
	delete all_tasks[elem.id];
}
