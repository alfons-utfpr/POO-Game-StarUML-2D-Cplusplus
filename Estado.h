#pragma once

namespace InvasaoAlienigena
{
	class Estado 
	{
	public:
		
		virtual ~Estado();
		virtual int executar() = 0;
		int codigoRetorno;
		//int finalFase();
	};
	
}
