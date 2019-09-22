package Structures;

public final class CharsLinkedList
{
	private CharsNode first;

	public CharsLinkedList()
	{
	}

	public CharsNode getFirst()
	{
		return first;
	}

	public void setFirst(CharsNode first)
	{
		this.first = first;
	}

	public void insert(char x)
	{
		CharsNode newNode = new CharsNode(x);

		if(first == null)
			first = newNode;
		else
		{
			CharsNode current = first;

			while(current.getNext() != null)
				current = current.getNext();
			current.setNext(newNode);
		}
	}

	@Override
	public String toString()
	{
		CharsNode current = first;
		String returned = "";

		while(current != null)
		{
			returned += current.getData();
			current = current.getNext();
		}

		return returned;
	}
}
