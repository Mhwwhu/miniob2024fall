#include "sql/executor/create_table_executor.h"

#include "common/log/log.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "session/session.h"
#include "sql/stmt/drop_table_stmt.h"
#include "storage/db/db.h"
#include "sql/executor/drop_table_executor.h"
#include "drop_table_executor.h"

RC DropTableExecutor::execute(SQLStageEvent* sql_event)
{
	Stmt* stmt = sql_event->stmt();
	Session* session = sql_event->session_event()->session();
	ASSERT(stmt->type() == StmtType::DROP_TABLE,
		"drop executor cannot run this command: %d",
		static_cast<int>(stmt->type()));
	DropTableStmt* drop_table_stmt = static_cast<DropTableStmt*>(stmt);
	Table* table = drop_table_stmt->GetTable();
	RC rc = session->get_current_db()->drop_table(table);
	return rc;
}