package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class MemebersAllService implements Service {

	public MemebersAllService() {
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public ArrayList<MemberDTO> execute(HttpServletRequest request, HttpServletResponse response) {
		// TODO Auto-generated method stub

		MemberDAO dao = MemberDAO.getInstacne();
		return dao.membersAll();
	}
	
}
