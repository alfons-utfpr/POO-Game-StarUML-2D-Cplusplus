#pragma once

namespace Jogo
{
	class Estado
	{
	public:
		virtual ~Estado();
		virtual int executar() = 0;

	};

}
