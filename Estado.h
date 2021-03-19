#pragma once

namespace exercicio
{
	class Estado
	{
	public:
		virtual ~Estado();
		virtual int executar() = 0;

	};

}
