package com.javalec.ex;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

public class MemberDAO {
	
	private String url = "jdbc:oracle:thin:@localhost:1521:xe";
	private String uid = "scott";
	private String upw = "tiger";
	
	public MemberDAO() {
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public ArrayList<MemberDTO> memberSelect() {
		
		ArrayList<MemberDTO> dtos = new ArrayList<MemberDTO>();
		
		Connection conn = null;
		Statement stmt = null;
		ResultSet set = null;
		
		try {
			conn = DriverManager.getConnection(url, uid, upw);
			stmt = conn.createStatement();
			set = stmt.executeQuery("select * from member");
			
			while (set.next()) {
				String name = set.getString("name");
				String id = set.getString("id");
				String pw = set.getString("pw");
				String phone1 = set.getString("phone1");
				String phone2 = set.getString("phone2");
				String phone3 = set.getString("phone3");
				String gender = set.getString("gender");
				
				MemberDTO dto = new MemberDTO(name, id, pw, phone1, phone2, phone3, gender);
				dtos.add(dto);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (set != null) set.close();
				if (stmt != null) stmt.close();
				if (conn != null) conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
		return dtos;
	}
}
