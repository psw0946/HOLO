<%@page import="com.javalec.ex.MemberDAO"%>
<%@page import="java.sql.Timestamp"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<% request.setCharacterEncoding("EUC-KR"); %>
<jsp:useBean id="dto" class="com.javalec.ex.MemberDTO" />
<jsp:setProperty name="dto" property="*" /> <!-- join.jsp���� �Ѿ�� �͵��� �̸��� �°� �˾Ƽ� ��������.(name�� property�� �ݵ�� ���ƾ� ��) -->
<%
	dto.setrDate(new Timestamp(System.currentTimeMillis()));
	MemberDAO dao = MemberDAO.getInstacne();
	if (dao.confirmId(dto.getId()) == MemberDAO.MEMBER_EXISTENT) {
%>
	<script language="javascript">
		alert("���̵� �̹� �����մϴ�.");
		history.back();
	</script>
<%
	} else {
		int ri = dao.insertMember(dto);
		if (ri == MemberDAO.MEMBER_JOIN_SUCCESS) {
			session.setAttribute("id", dto.getId());
%>
	<script language="javascript">
		alert("ȸ�������� �����մϴ�.");
		document.location.href="login.jsp";
	</script>
<%
		} else {
%>
	<script language="javascript">
		alert("ȸ�����Կ� �����߽��ϴ�.");
		document.location.href="login.jsp";
	</script>
<%
		}
	}
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

</body>
</html>