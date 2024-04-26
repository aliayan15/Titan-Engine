#pragma once
namespace te
{
	enum class ActionType
	{
		Pressed,
		Released
	};
	enum class ActionName
	{
		Up
	};

	struct Action
	{
	public:
		Action();
		Action(const ActionName name, const ActionType type);
		const ActionName name() const;
		const ActionType type() const;
	private:
		ActionName m_name;
		ActionType m_type;
	};
}
