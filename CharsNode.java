package Structures;

public final class CharsNode
{
	private char data;
	private CharsNode next;

	public CharsNode(char data)
	{
		this.data = data;
	}

	public char getData()
	{
		return data;
	}

	public void setData(char data)
	{
		this.data = data;
	}

	public CharsNode getNext()
	{
		return next;
	}

	public void setNext(CharsNode next)
	{
		this.next = next;
	}

	@Override
	public String toString()
	{
		return data + "";
	}

}
